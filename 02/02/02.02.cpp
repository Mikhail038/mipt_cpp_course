#include <cmath>
#include <iostream>
#include <print>
#include <cstdlib>


bool equal_zero(const double x) {
    const double epsilon = 1e-5;

    return (std::abs(x) < epsilon);
}

enum class Roots {None, One, Two, Infinite};

struct QuadraticSolution {
    Roots roots = Roots::None;

    double x1 = 0;
    double x2 = 0;

    void print() const {
        switch (roots) {
            case Roots::None:
                std::print("No roots\n");
                break;
            case Roots::One:
                std::print("One root {}\n", x1);
                break;
            case Roots::Two:
                std::print("Two roots {} {}\n", x1, x2);
                break;
            case Roots::Infinite:
                std::print("Infinite roots\n");
                break;
        }
    }
};

QuadraticSolution solve_linear(const double b, const double c) {
    if (equal_zero(b) && equal_zero(c)) {
        return {Roots::Infinite};
    }

    if (equal_zero(b)) {
        return {Roots::None};
    }

    const auto x = - c / b;
    return {Roots::One, x};
}

QuadraticSolution solve_quadratic(const double a, const double b, const double c) {
    if (equal_zero(a)) {
        return solve_linear(b, c);
    }

    const auto discriminant = b * b - 4 * a * c;

    if (equal_zero(discriminant)) {
        const auto x = - b / (2 * a);
        return {Roots::One, x};
    }

    if (discriminant < 0) {
        return {Roots::None};
    }

    const auto sqrt_discriminant = std::sqrt(discriminant);

    const auto x1 = (- b - sqrt_discriminant) / (2 * a);
    const auto x2 = (- b + sqrt_discriminant) / (2 * a);
    return {Roots::Two, x1, x2};
}

int main() {
    std::print("Enter a b c coefficients:\n");
    double a = 0, b = 0, c = 0;
    if (!(std::cin >> a >> b >> c)) {
        std::print(stderr, "error: wrong entered values. 3 double expected\n");
        return EXIT_FAILURE;
    }

    const auto solution = solve_quadratic(a, b, c);

    solution.print();

    return 0;
}