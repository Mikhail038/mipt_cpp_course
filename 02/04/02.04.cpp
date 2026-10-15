#include <print>

int cube(const int x) {
    return x * x * x;
}

int main() {
    const auto base = 10; //10 for decimal, 2 for binary, etc.
    auto counter = 1;

    for (int hundreds = 1; hundreds < base; hundreds++) {
        for (int tens = 0; tens < base; tens++) {
            for (int units = 0; units < base; units++) {
                const auto number = hundreds * base * base + tens * base + units;
                const auto sum_of_cubes = cube(hundreds) + cube(tens) + cube(units);

                if (number == sum_of_cubes) {
                    std::print("{} three-digit Armstrong number is {}\n", counter, number);
                    counter++;
                }
            }
        }
    }

    return 0;
}