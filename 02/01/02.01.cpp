#include <cmath>
#include <iostream>
#include <print>
#include <limits>
#include <cstdlib>

//count fibonacci F(n) iteratively and return max n, such that F(n) does not overflow int limit
constexpr int max_fib_int() {
    constexpr auto limit = std::numeric_limits<int>::max();

    int a = 0, b = 1; //first two fib numbers
    int n = 1;

    while (b < limit - a) {
        b = b + a;
        a = b - a;

        n++;
    }

    return n;
}

//count fibonacci F(n) using Binet formula
int fib_binet(const int n) {
    const auto sqrt_5 = std::sqrt(5.0);

    //Fibonacci numbers can be roughly counted as numbers in geometric progression

    //two roots of 'q^2 = q + 1' equation
    const auto phi = (1 + sqrt_5) / 2;
    const auto psi = (1 - sqrt_5) / 2;

    //this formula is combination of phi and psi with initial conditions F(0) = 0, F(1) = 1
    //operating with double requires rounding to get rid of floating-point error
    return static_cast<int>(std::round(
        (std::pow(phi, n)
        - std::pow(psi, n)) / sqrt_5));
}

int main() {
    constexpr auto max_n = max_fib_int();

    int n = 0;
    if (!(std::cin >> n)) {
        std::print(stderr, "error: entered value is wrong. [0, {}] integer expected\n", max_n);
        return EXIT_FAILURE;
    }

    if (n < 0 || n > max_n) {
        std::print(stderr, "error: '{}' is wrong value. [0, {}] expected\n", n, max_n);
        return EXIT_FAILURE;
    }

    std::print("F({}) = {}\n", n, fib_binet(n));

    return 0;
}