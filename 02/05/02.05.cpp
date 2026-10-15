#include <iostream>
#include <limits>
#include <print>
#include <cstdlib>
#include <cmath>

double pi_by_series(const double accuracy) {
    double result = 0;
    double sign = 1;
    double denominator = 1;
    double step = 1;

    while (std::abs(step) > accuracy) {
        result += step;

        denominator += 2;
        sign *= -1;
        step = 1 / (sign * denominator);
    }

    return 4 * result;
}

double e_by_series(const double accuracy) {
    double result = 1;
    int number = 2;
    double step = 1;

    while (std::abs(step) > accuracy) {
        result += step;

        step /= number;
        number++;
    }

    return result;
}

int main() {
    // std::numeric_limits<double>::epsilon() may be too precise and lead to hang of PC
    const auto min_epsilon = 1e-9;

    double epsilon = 0;
    if (!(std::cin >> epsilon) || epsilon < min_epsilon) {
        std::print(stderr, "error: wrong entered values. expected positive double more than {}\n", min_epsilon);
        return EXIT_FAILURE;
    }

    std::print("Pi ~ {}\n", pi_by_series(epsilon));
    std::print("e  ~ {}\n", e_by_series(epsilon));

    return 0;
}