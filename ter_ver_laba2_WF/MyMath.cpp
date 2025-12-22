#include "MyMath.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

double MyMath::generate_exponential(double Lambda)
{
    
    double U = rand() / (double)RAND_MAX;
    // max(U, 1e-9) чтобы избежать log(0)
    double log1 = log(U);
    return -(1.0 / Lambda) * log1;
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

    if (k <= 0 || lambda_k <= 0.0 || N <= 0) return;

    
    
    sample.clear();
    for (int i = 0; i < N; ++i) {
        double min_val = INFINITY;
        for (int j = 0; j < k; j++) {
            double generate_x = generate_exponential(lambda_k);
            if (min_val > generate_x) {
                min_val = generate_x;
            }
            
        }
        sample.push_back(min_val);
    }
    sort(sample.begin(), sample.end());

    
    
}

void MyMath::part_2(int m)
{

    if (N == 0 || sample.empty()) return;

    R_bar = sample.back() - sample.front();
    Lambda = k * lambda_k;
    E_eta = 1.0 / Lambda;
    D_eta = 1.0 / (Lambda * Lambda);
    Me_eta = log(2.0) / Lambda;
    if (N % 2 != 0) {
        Me_hat = sample[N / 2];
    }
    else {
        Me_hat = (sample[N / 2 - 1] + sample[N / 2]) / 2.0;
    }

    sum = accumulate(sample.begin(), sample.end(), 0.0);
    x_bar = sum / N;

    double sum_sq_diff = 0.0;
    for (double x : sample) {
        sum_sq_diff += pow(x - x_bar, 2);
    }
    S_sq = sum_sq_diff / N;
    R_bar = sample.empty() ? 0.0 : sample.back() - sample.front();


    for (int j = 1; j <= N; ++j) {
        double xj = sample[j - 1];
        double Fj_theoretical = theoretical_cdf(xj, Lambda);
        double F_hat_j = (double)j / N;
        double F_hat_j_minus_1 = (double)(j - 1) / N;

        double D_top = abs(F_hat_j - Fj_theoretical);
        double D_bottom = abs(Fj_theoretical - F_hat_j_minus_1);

        // Проверяем отклонение в верхней точке ступеньки
        if (D_top > D_statistic) {
            D_statistic = D_top;
            x_mera_d = xj;
            j_mera_d = j; // Сохраняем порядковый номер
        }

        // Проверяем отклонение в нижней точке ступеньки
        if (D_bottom > D_statistic) {
            D_statistic = D_bottom;
            x_mera_d = xj;
            j_mera_d = j; // Сохраняем порядковый номер
        }
    }


    std::vector<double> bounds;
    int k_intervals = 0;
    double safe_R_bar = (R_bar <= 1e-9) ? 1e-6 : R_bar;
    double a_j_start = sample.front();


    if (m == gistogramma_vector.size())
    {
        
        bounds = gistogramma_vector;
        k_intervals = bounds.size() - 1;

        // Сортировка и пересчет размаха на случай, если пользователь ввел границы не по порядку
        std::sort(bounds.begin(), bounds.end());
        R_bar = bounds.back() - bounds.front();
    }
    else 
    {
        
        
        k_intervals = std::max(1, m); 

        // Расчет равномерных границ
        double delta_prime = safe_R_bar / k_intervals;

        bounds.reserve(k_intervals + 1);
        for (int i = 0; i <= k_intervals; ++i) {
            bounds.push_back(a_j_start + (double)i * delta_prime);
        }
        R_bar = safe_R_bar;
    }


    gistogramma_vector = bounds;


    if (k_intervals <= 0) {
        interval_series_results.clear();
        max_density_deviation = 0.0;
        return;
    }


    interval_series_results.clear();
    max_density_deviation = 0.0;
    auto current_it = sample.begin();


    for (int j = 0; j < k_intervals; ++j)
    {
        double start = bounds[j];
        double end = bounds[j + 1];

        double current_delta_prime = end - start;

        // 1. Подсчет частоты n_j: Используем std::upper_bound
        // std::upper_bound находит первый элемент, строго больший чем end.
        auto next_it = std::upper_bound(current_it, sample.end(), end);

        // Корректировка для последнего интервала [start, end]: 
        // Включаем максимальный элемент выборки, даже если он равен 'end'.
        if (j == k_intervals - 1 && !sample.empty() && *(sample.end() - 1) == end) {
            next_it = sample.end();
        }

        int n_j_current = std::distance(current_it, next_it);

        // 2. Вычисление середины интервала и плотностей
        double zj = start + current_delta_prime / 2.0;

        // f(z_j) = Теоретическая плотность
        double theoretical_density = theoretical_pdf(zj, Lambda);

        // h_j = Выборочная плотность: n_j / (N * Δ')
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

        // Передвигаем итератор к началу следующего интервала
        current_it = next_it;
    }
}

void MyMath::part_3(double alpha) {
    vector_q_j.clear();
    if (chi_square_bounds.empty()) return;

    // Сортируем на всякий случай, если пользователь ввел не по порядку
    std::sort(chi_square_bounds.begin(), chi_square_bounds.end());

    // Формируем интервалы согласно методичке:
    // Delta_1 = [0, z1)
    // Delta_2 = [z1, z2) ...
    // Delta_k = [zk-1, inf)

    int k_chi = chi_square_bounds.size() + 1; // Число интервалов
    R0_statistic = 0.0;

    // Временный вектор для хранения всех границ, включая 0 и "бесконечность"
    std::vector<double> full_bounds;
    full_bounds.push_back(0.0);
    for (double z : chi_square_bounds) full_bounds.push_back(z);
    full_bounds.push_back(1e18); // "Бесконечность"
    
    for (int j = 0; j < k_chi; ++j) {
        double start = full_bounds[j];
        double end = full_bounds[j + 1];

        // 1. Теоретическая вероятность q_j
        double q_j = theoretical_cdf(end, Lambda) - theoretical_cdf(start, Lambda);

        vector_q_j.push_back(q_j);
        summa_qj += q_j;
       
        // 2. Считаем n_j (сколько элементов выборки попало в [start, end))
        // Используем std::lower_bound для эффективного поиска в отсортированной выборке sample
        auto it_start = std::lower_bound(sample.begin(), sample.end(), start);
        auto it_end = std::lower_bound(sample.begin(), sample.end(), end);
        int n_j = std::distance(it_start, it_end);

        // 3. Считаем вклад в R0
        if (q_j > 0) {
            double expected = (double)N * q_j;
            R0_statistic += pow(n_j - expected, 2) / expected;
        }
    }

    // Степени свободы df = k - 1. Так как k = nodes + 1, то df = nodes.
    int df = chi_square_bounds.size();
    p_value = chi_square_p_value(R0_statistic, df);
    cout << "Stepeni svobodi = " << df << endl;
    cout << "R0_statistic = " << R0_statistic << endl;

    hypothesis_accepted = (p_value >= alpha);
    cout << "P_value = " << p_value << endl;
}


double MyMath::chi_square_p_value(double R0, int df) {
    if (R0 < 0 || df < 1) return 1.0;

    // Для экспоненциального хвоста при больших R0 и малых df 
    // используем формулу связи с неполной гамма-функцией.
    // Если df четное: df = 2m
    if (df % 2 == 0) {
        double m = df / 2.0;
        double sum = 1.0;
        double term = 1.0;
        for (int i = 1; i < m; i++) {
            term *= (R0 / 2.0) / i;
            sum += term;
        }
        return sum * exp(-R0 / 2.0);
    }
    // Если df нечетное: используем приближение через функцию ошибок (erfc)
    // или более общий ряд Тейлора. 
    else {
        // Для простоты и точности воспользуемся общим алгоритмом для любого df
        return regularized_upper_incomplete_gamma(df / 2.0, R0 / 2.0);
    }
}

double MyMath::regularized_upper_incomplete_gamma(double a, double x) { // 
    if (x <= 0) return 1.0;

    // Разложение в ряд для P(a, x) = (x^a * e^-x) / Gamma(a) * sum(...)
    // Q(a, x) = 1 - P(a, x)
    double sum = 1.0 / a;
    double term = sum;
    for (int i = 1; i < 100; i++) {
        term *= x / (a + i);
        sum += term;
        if (term < 1e-12) break; // Точность
    }

    double result = sum * pow(x, a) * exp(-x) / tgamma(a);
    return 1.0 - result;
}


