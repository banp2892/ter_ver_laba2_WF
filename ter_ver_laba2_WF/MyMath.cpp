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

void MyMath::part_2()
{
    if (N == 0) return;

    // Предполагаем, что sample (выборка) уже отсортирована и N > 0.

    // 1. Расчет размаха выборки R_bar
    R_bar = sample.back() - sample.front();

    // 2. Расчет медиан (Теоретическая и Выборочная)
    Me_eta = log(2.0) / Lambda;
    if (N % 2 != 0) {
        // Нечетный N: Ме = X_((N+1)/2)
        Me_hat = sample[N / 2];
    }
    else {
        // Четный N: Ме = (X_(N/2) + X_(N/2 + 1)) / 2
        Me_hat = (sample[N / 2 - 1] + sample[N / 2]) / 2.0;
    }

    // 3. Статистика Колмогорова-Смирнова (D)
    D_statistic = 0.0;
    for (int j = 1; j <= N; ++j) {
        double xj = sample[j - 1];
        // F(x) = 1 - exp(-Lambda * x)
        double Fj_theoretical = theoretical_cdf(xj, Lambda);

        // F_hat_j = j/N (после скачка)
        double F_hat_j = (double)j / N;
        // F_hat_j_minus_1 = (j-1)/N (перед скачком)
        double F_hat_j_minus_1 = (double)(j - 1) / N;

        double D_top = abs(F_hat_j - Fj_theoretical);
        double D_bottom = abs(Fj_theoretical - F_hat_j_minus_1);

        D_statistic = max({ D_statistic, D_top, D_bottom });
    }

    // =================================================================
    // 4. РАСЧЕТ ИНТЕРВАЛЬНОГО РЯДА (ДЛЯ ГИСТОГРАММЫ И ПЛОТНОСТИ)
    // =================================================================

    // --- A. Определение числа интервалов (k_intervals = m) ---
    int k_intervals;
    // Используем формулу Стерджеса: max(3, округление(1 + 3.322 * log10(N)))
    k_intervals = max(3, (int)round(1.0 + 3.322 * log10(N)));
    // Убедимся, что k_intervals не меньше 1
    if (k_intervals == 0) k_intervals = 1;

    // --- B. Определение границ и ширины ---
    double safe_R_bar = (R_bar <= 1e-9) ? 1e-6 : R_bar; // Защита от нулевого размаха
    double delta_prime = safe_R_bar / k_intervals;      // Ширина интервала Δ'
    double a_j_start = sample.front();                  // Начало первого интервала

    interval_series_results.clear();
    max_density_deviation = 0.0;

    int current_sample_index = 0;

    // --- C. Цикл по всем интервалам ---
    for (int j = 0; j < k_intervals; ++j)
    {
        double start = a_j_start + (double)j * delta_prime;
        double end = a_j_start + (double)(j + 1) * delta_prime;

        // 1. Подсчет частоты n_j
        int n_j_current = 0;

        while (current_sample_index < N) {
            double x = sample[current_sample_index];

            // Условие попадания: [start, end). Последний интервал включает end.
            bool includes_end = (j == k_intervals - 1);
            if (x < end || (includes_end && x <= end)) {
                n_j_current++;
                current_sample_index++;
            }
            else {
                break;
            }
        }

        // 2. Вычисление середина интервала и плотностей
        double zj = start + delta_prime / 2.0; // Середина интервала z_j

        // f(z_j) = Теоретическая плотность (Lambda * exp(-Lambda * z_j))
        double theoretical_density = theoretical_pdf(zj, Lambda);

        // h_j = Выборочная плотность (высота столбца гистограммы)
        double empirical_density = (double)n_j_current / (N * delta_prime);

        // 3. Сохраняем данные для вывода в таблицу и график
        IntervalData data;
        data.interval_start = start;
        data.interval_end = end;
        data.z_j = zj;
        data.n_j = n_j_current;
        data.f_teor = theoretical_density;

        interval_series_results.push_back(data);

        // 4. Обновляем максимальное отклонение плотности
        double deviation = abs(empirical_density - theoretical_density);
        max_density_deviation = max(max_density_deviation, deviation);
    }
}