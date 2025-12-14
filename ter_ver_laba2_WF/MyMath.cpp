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

    // 1. Расчет медиан (сохранение в членах класса)
    Me_eta = log(2.0) / Lambda;
    if (N % 2 != 0) {
        Me_hat = sample[N / 2];
    }
    else {
        Me_hat = (sample[N / 2 - 1] + sample[N / 2]) / 2.0;
    }

    // 2. Статистика Колмогорова-Смирнова (D) (сохранение в члене класса)
    D_statistic = 0.0;
    for (int j = 1; j <= N; ++j) {
        double xj = sample[j - 1];
        double Fj_theoretical = theoretical_cdf(xj, Lambda);
        double F_hat_j = (double)j / N;
        double F_hat_j_minus_1 = (double)(j - 1) / N;

        double D_top = abs(F_hat_j - Fj_theoretical);
        double D_bottom = abs(Fj_theoretical - F_hat_j_minus_1);

        D_statistic = max({ D_statistic, D_top, D_bottom });
    }


    // 3. Расчет максимального отклонения плотности (Max Diff) (для гистограммы)
    int k_intervals;
    // Используем формулу Стерджеса для определения числа интервалов
    k_intervals = max(3, (int)round(1.0 + 3.322 * log10(N)));

    if (k_intervals == 0) k_intervals = 1;

    double safe_R_bar = (R_bar == 0.0) ? 1e-6 : R_bar;
    double delta_prime = safe_R_bar / k_intervals;

    // Расчет частот n_j
    vector<int> n_j(k_intervals, 0);
    double a_j_start = sample.front();

    for (double x : sample) {
        int index = 0;
        if (delta_prime > 0) {
            index = floor((x - a_j_start) / delta_prime);
        }

        if (index >= k_intervals) {
            index = k_intervals - 1;
        }

        n_j[index]++;
    }

    // Расчет максимального отклонения плотности
    max_density_deviation = 0.0;
    for (int j = 0; j < k_intervals; ++j) {
        double interval_start = a_j_start + j * delta_prime;
        // z_j - середина интервала
        double zj = interval_start + delta_prime / 2.0;

        double theoretical_density = theoretical_pdf(zj, Lambda);
        // Выборочная плотность: n_j / (N * длина_интервала)
        double empirical_density = (double)n_j[j] / (N * delta_prime);

        double deviation = abs(empirical_density - theoretical_density);
        max_density_deviation = max(max_density_deviation, deviation);
    }

}