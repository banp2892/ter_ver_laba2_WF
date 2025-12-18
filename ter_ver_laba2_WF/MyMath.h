#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>


using namespace std;




class MyMath
{

public:
    vector<double> gistogramma_vector;
    vector<double> chi_square_bounds;
    int k;
    double lambda_k;
    int N;
    double Lambda;
    double E_eta;
    double D_eta;
    vector<double> sample;
    double sum;
    double x_bar;
    double S_sq;
    double R_bar;
    // Добавленные поля для результатов Части 2
    double Me_eta; // Теоретическая медиана
    double Me_hat; // Выборочная медиана
    double D_statistic; // Статистика Колмогорова-Смирнова
    double max_density_deviation; // Максимальное отклонение плотности

    double R0_statistic; // Значение R0
    double p_value;      // Вычисленное F(R0)
    bool hypothesis_accepted; // Итог: true - принимаем, false - отвергаем

    

    struct IntervalData {
        double z_j;          // Середина интервала
        int n_j;             // Абсолютная частота
        double f_teor;       // Теоретическая плотность f(z_j)
        double interval_start; // Начало интервала
        double interval_end;   // Конец интервала
        // Если нужен критерий Пирсона:
        double P_j;            // Теоретическая вероятность попадания в интервал
    };

    // Результаты интервального ряда
    std::vector<IntervalData> interval_series_results;

    // Конструктор для инициализации
    MyMath(int k_val, double lambda_k_val, int N_val) :
        k(k_val), lambda_k(lambda_k_val), N(N_val), Lambda(0.0), E_eta(0.0), D_eta(0.0),
        sum(0.0), x_bar(0.0), S_sq(0.0), R_bar(0.0), Me_eta(0.0), Me_hat(0.0),
        D_statistic(0.0), max_density_deviation(0.0)
    {
    }



    double generate_exponential(double Lambda);

    // Теоретическая функция распределения F(x) = 1 - exp(-Lambda * x)
    double theoretical_cdf(double x, double Lambda);

    // Теоретическая плотность распределения f(x) = Lambda * exp(-Lambda * x)
    double theoretical_pdf(double x, double Lambda);

    void part_1();
    void part_2(int m);
    void part_3(double alpha);
    double chi_square_p_value(double R0, int df);
    double regularized_upper_incomplete_gamma(double a, double x);
    
    // void part_3(double alpha); // Для следующего шага
};