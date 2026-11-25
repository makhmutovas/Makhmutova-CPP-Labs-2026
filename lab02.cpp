#include <cmath>
#include <iomanip>
#include <iostream>

namespace {

const int kMin{0};
const int kDivisor{5};

const int kBound{0};
const int kHighStartPoint{2};
const int kHighEndPoint{8};
const int kHighStep{2};
const int kLowStartPoint{3};
const int kLowEndPoint{9};
const int kLowStep{3};

const double eps{1e-6};
const double h{0.2};
const int kXWide{8};
const int kWide{14};
const int kNWide{6};
const int steps{5};
const double kMultiplier{2.0};

const int kSmallCount{3};
const int kMediumCount{5};
const int kLargeCount{10};

}  // namespace

int main() {
    int choice{1};

    while (choice) {
        std::cout << "Выберите задачу для решения(1/2/3/4) 0-exit: " << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 0: {
                std::cout << "Выход" << std::endl;
                break;
            }
            case 1: {
                int n{};
                int m{};
                int sum{};

                std::cout << "Введите n и m (m<n) : ";
                std::cin >> n >> m;

                if (m <= kMin || m >= n) {
                    std::cout << "Ошибка" << std::endl;
                    break;
                }

                for (int i = kDivisor; i <= n; i += kDivisor) {
                    if ((i % m) != 0) {
                        sum += i;
                    }
                }
                std::cout << "Сумма: " << sum << std::endl;
                break;
            }
            case 2: {
                double a;
                double S{1};

                std::cout << "Введите а: ";
                std::cin >> a;

                if (a >= kBound) {
                    for (int i = kHighStartPoint; i <= kHighEndPoint; i += kHighStep) {
                        S *= i * i;
                    }
                    S = S - a;
                }

                if (a < kBound) {
                    for (int i = kLowStartPoint; i <= kLowEndPoint; i += kLowStep) {
                        S *= (i - 2);
                    }
                }
                std::cout << std::fixed << std::setprecision(2) << "S = " << S << std::endl;
                break;
            }
            case 3: {
                std::cout << std::fixed << std::setprecision(6);
                std::cout << std::setw(kXWide) << "x";
                std::cout << std::setw(kWide) << "Y(x)";
                std::cout << std::setw(kWide) << "S(x)";
                std::cout << std::setw(kNWide) << "N" << std::endl;

                for (int j = kMin; j < steps; j++) {
                    double x = j * h;

                    double Y = std::log((1 + x) / (1 - x));

                    double term = kMultiplier * x;
                    double sum = term;
                    int N = 1;

                    while (true) {
                        double next = term * x * x * (2 * N - 1) / (2 * N + 1);
                        if (next < eps)
                            break;
                        term = next;
                        sum += term;
                        N++;
                    }

                    std::cout << std::setw(kXWide) << x << std::setw(kWide) << Y << std::setw(kWide) << sum << std::setw(kNWide) << N << std::endl;
                }
                break;
            }

            case 4: {
                int n;
                double x;

                std::cout << "Введите натуральное значение n и x: ";
                std::cin >> n >> x;

                if (n < 1) {
                    std::cout << "Ошибка: n должно быть натуральным" << std::endl;
                } else {
                    std::cout << std::fixed << std::setprecision(6);
                }

                double y = x;
                double term = x;

                for (int k{1}; k <= n; k++) {
                    if (k == 1) {
                        term = x * x / 2;
                    } else {
                        term = term * x * (k - 1) / (2.0 * k);
                    }
                    y += term;

                    int count = k + 1;
                    if (count == kSmallCount || count == kMediumCount || count == kLargeCount) {
                        std::cout << "Частичная сумма при " << count << std::endl;
                        std::cout << "слагаемых:  " << y << std::endl;
                    }
                }
                std::cout << "y (n = " << n << ") = " << y << std::endl;
                break;
            }

            default: {
                std::cout << "Такой задачи нет" << std::endl;
            }
        }
    }
    return 0;
}
