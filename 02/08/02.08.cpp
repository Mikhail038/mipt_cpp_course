#include <vector>
#include <print>
#include <cstddef>

using value_t = unsigned long long;

value_t next_collatz(const value_t x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return 3 * x + 1;
    }
}

std::size_t count_length(const value_t x, std::vector<std::size_t>& sequence_lengths) {
    if (x < sequence_lengths.size()) {
        if (sequence_lengths[x] == 0) {
            sequence_lengths[x] = 1 + count_length(next_collatz(x), sequence_lengths);
        }
        return sequence_lengths[x];
    }

    return 1 + count_length(next_collatz(x), sequence_lengths);
}

int main() {
    const value_t max_num = 100;
    std::vector<std::size_t> sequence_lengths(max_num + 1, 0);
    sequence_lengths[1] = 1; // base case to stop recursion: the length of the Collatz sequence for 1 is 1

    value_t num_with_max_length = 0;
    std::size_t max_length = 0;
    for (value_t num = 1; num <= max_num; num++) {
        const std::size_t length = count_length(num, sequence_lengths);
        if (length > max_length) {
            max_length = length;
            num_with_max_length = num;
        }
    }

    std::print("Max Collatz sequence length for numbers up to {} is {} for {}\n", max_num, max_length, num_with_max_length);

    return 0;
}