#include "MyMath.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

double MyMath::generate_exponential(double Lambda)
{
    // Использование time(0) в srand() гарантирует разную последовательность при каждом запуске
    // Но rand() должна быть инициализирована только один раз в начале программы.
    // Я оставляю srand(time(0)) в part_1() для простоты, как у вас было.
    double U = rand() / (double)RAND_MAX;
    // max(U, 1e-9) чтобы избежать log(0)
    return -(1.0 / Lambda) * log(max(U, 1e-9));
}

double MyMath::theoretical_cdf(double x, double Lambda)
{
    if (x <= 0) return 0.0;
    return 1.0 - exp(-Lambda * x);
}

double MyMath::theoretical_pdf(double x, double Lambda)
{
    if (x <= 0) return 0.0;
    return Lambda * exp(-Lambda * x);
}

void MyMath::part_1()
{
    // --- 1. Проверка условий ---
    if (k <= 0 || lambda_k <= 0.0 || N <= 0) return;

    // --- 2. Расчет теоретических характеристик ---
    Lambda = (double)k / lambda_k; // Параметр Lambda = k * (1/lambda_k)
    E_eta = 1.0 / Lambda;
    D_eta = 1.0 / (Lambda * Lambda);

    // --- 3. Моделирование (Розыгрыш значений) ---
    srand((unsigned int)time(0));
    sample.clear();
    for (int i = 0; i < N; ++i) {
        sample.push_back(generate_exponential(Lambda));
    }
    sort(sample.begin(), sample.end());

    // --- 4. Расчет выборочных характеристик (для Части 2) ---
    sum = accumulate(sample.begin(), sample.end(), 0.0);
    x_bar = sum / N;
    double sum_sq_diff = 0.0;
    for (double x : sample) {
        sum_sq_diff += pow(x - x_bar, 2);
    }
    S_sq = sum_sq_diff / N;
    R_bar = sample.empty() ? 0.0 : sample.back() - sample.front();

}

void MyMath::part_2() // m здесь теперь не используется, но оставлено для совместимости
{
    // Проверка на пустую выборку
    if (N == 0 || sample.empty()) return;

    // 1. Расчет размаха выборки R_bar
    R_bar = sample.back() - sample.front();

    // 2. Расчет медиан
    Me_eta = log(2.0) / Lambda;

    if (N % 2 != 0) {
        // Нечетное N: берем средний элемент
        Me_hat = sample[N / 2];
    }
    else {
        // Четное N: берем среднее двух центральных элементов
        Me_hat = (sample[N / 2 - 1] + sample[N / 2]) / 2.0;
    }

    // 3. Статистика Колмогорова-Смирнова (D)
    D_statistic = 0.0;
    for (int j = 1; j <= N; ++j) {
        double xj = sample[j - 1];
        double Fj_theoretical = theoretical_cdf(xj, Lambda);
        double F_hat_j = (double)j / N;
        double F_hat_j_minus_1 = (double)(j - 1) / N;

        double D_top = abs(F_hat_j - Fj_theoretical);
        double D_bottom = abs(Fj_theoretical - F_hat_j_minus_1);
        D_statistic = std::max({ D_statistic, D_top, D_bottom });
    }

    // ⭐ Теперь part_2 завершается здесь. Логика гистограммы вынесена.

    // Если нужно, вызываем логику гистограммы:
    // part_2_gist(m); 
    // Однако, лучше вызывать part_2_gist() из MyForm, когда границы готовы.
}

void MyMath::part_2_gist(int m)
{
    // Проверка
    if (N == 0 || sample.empty()) return;

    // =================================================================
    // 4. ОПРЕДЕЛЕНИЕ ИНТЕРВАЛЬНОГО РЯДА (ЛОГИКА ВЫБОРА ГРАНИЦ)
    // =================================================================

    std::vector<double> bounds;
    int k_intervals = 0;
    double safe_R_bar = (R_bar <= 1e-9) ? 1e-6 : R_bar;
    double a_j_start = sample.front();

    // --- ПРИОРИТЕТ 1: m > 0. Используем gistogramma_vector, если он заполнен ---
    // (gistogramma_vector теперь заполняется из MyForm после вызова ShowGistogrammaInputDialog)
    if (m > 0 && !gistogramma_vector.empty()) // Изменено условие для проверки
    {
        // 1. Используем границы, введенные пользователем (они уже в gistogramma_vector)
        // ВНИМАНИЕ: Если gistogramma_vector заполнен, его размер должен быть >= 2
        bounds = gistogramma_vector;
        k_intervals = bounds.size() - 1;

        // Сортировка и пересчет размаха (на случай, если пользователь ввел не по порядку, 
        // хотя InputForm должен это проверять)
        std::sort(bounds.begin(), bounds.end());
        R_bar = bounds.back() - bounds.front();
        gistogramma_vector = bounds;
    }
    else // m <= 0 ИЛИ m > 0, но пользователь не ввел границы (gistogramma_vector пуст)
    {
        // 2. АВТОМАТИЧЕСКАЯ ГЕНЕРАЦИЯ ГРАНИЦ

        if (m > 0) {
            // Если m > 0, но границ нет, используем m как число интервалов (равномерно)
            k_intervals = m;
        }
        else {
            // Если m <= 0, используем правило Стёрджесса
            k_intervals = std::max(3, (int)std::round(1.0 + 3.322 * std::log10(N)));
        }

        k_intervals = std::max(1, k_intervals); // Минимум 1 интервал

        // Расчет равномерных границ
        double delta_prime = safe_R_bar / k_intervals;

        bounds.reserve(k_intervals + 1);
        for (int i = 0; i <= k_intervals; ++i) {
            bounds.push_back(a_j_start + (double)i * delta_prime);
        }
        R_bar = safe_R_bar;

        // --- ОБЯЗАТЕЛЬНОЕ ЗАПОЛНЕНИЕ gistogramma_vector ---
        gistogramma_vector = bounds;
    }

    // Если нет интервалов, выходим
    if (k_intervals <= 0) {
        interval_series_results.clear();
        max_density_deviation = 0.0;
        return;
    }

    // =================================================================
    // 5. ПОДСЧЕТ ЧАСТОТ И СРАВНЕНИЕ ПЛОТНОСТЕЙ (ОБЩАЯ ЛОГИКА)
    // =================================================================

    interval_series_results.clear();
    max_density_deviation = 0.0;
    auto current_it = sample.begin();

    // --- Цикл по всем интервалам ---
    for (int j = 0; j < k_intervals; ++j)
    {
        double start = bounds[j];
        double end = bounds[j + 1];

        double current_delta_prime = end - start;

        // 1. Подсчет частоты n_j: Используем std::upper_bound
        auto next_it = std::upper_bound(current_it, sample.end(), end);

        if (j == k_intervals - 1 && !sample.empty() && *(sample.end() - 1) == end) {
            next_it = sample.end();
        }

        int n_j_current = std::distance(current_it, next_it);

        // 2. Вычисление середины интервала и плотностей
        double zj = start + current_delta_prime / 2.0;

        double theoretical_density = theoretical_pdf(zj, Lambda);

        double empirical_density = 0.0;
        if (current_delta_prime > 1e-9) {
            empirical_density = (double)n_j_current / (N * current_delta_prime);
        }

        // 3. Сохраняем данные
        IntervalData data;
        data.interval_start = start;
        data.interval_end = end;
        data.z_j = zj;
        data.n_j = n_j_current;
        data.f_teor = theoretical_density;

        interval_series_results.push_back(data);

        // 4. Обновляем максимальное отклонение плотности
        double deviation = std::abs(empirical_density - theoretical_density);
        max_density_deviation = std::max(max_density_deviation, deviation);

        current_it = next_it;
    }
}


