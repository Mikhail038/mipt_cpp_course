#include <iostream>
#include <print>
#include <string_view>

int main() {
    const auto symbol_max_width = 10;
    const auto code_max_width   = 3;

    std::print("enter symbols and press Enter to stop\n");

    char symbol = '\0';
    while (std::cin.get(symbol)) {
        std::string_view symbol_type = "nill";

        switch (symbol) {
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H':
            case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P':
            case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
            case 'Y': case 'Z':
                symbol_type = "a capital letter";
                break;

            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':
            case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p':
            case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x':
            case 'y': case 'z':
                symbol_type = "a lowercase letter";
                break;

            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7':
            case '8': case '9':
                symbol_type = "a digit";
                break;

            case '!': case '"': case '#': case '$': case '%': case '&': case '\'': case '(':
            case ')': case '*': case '+': case ',': case '-': case '.': case '/': case ':':
            case ';': case '<': case '=': case '>': case '?': case '@': case '[': case '\\':
            case ']': case '^': case '_': case '`': case '{': case '|': case '}': case '~':
                symbol_type = "a punctuation sign";
                break;

            case '\n':
                return 0;

            default:
                symbol_type = "unqualified";
        }

        std::print("{:<{}?} code [{:>{}d}] is {}\n", symbol, symbol_max_width, symbol, code_max_width, symbol_type);
    }
}

//GNU case ranges are not standert => warning from -Wpedantic
/*
    case 'A' ... 'Z':
        symbol_type = "a capital letter";
        break;

    case 'a' ... 'z':
        symbol_type = "a lowercase letter";
        break;

    case '0' ... '9':
        symbol_type = "a digit";
        break;

$ LC_ALL=C g++ -std=c++23 -Wpedantic 02/03/02.03_test.cpp
02/03/02.03_test.cpp: In function 'int main()':
02/03/02.03_test.cpp:13:9: warning: range expressions in switch statements are non-standard [-Wpedantic]
   13 |         case 'A' ... 'Z':
      |         ^~~~
02/03/02.03_test.cpp:17:9: warning: range expressions in switch statements are non-standard [-Wpedantic]
   17 |         case 'a' ... 'z':
      |         ^~~~
02/03/02.03_test.cpp:21:9: warning: range expressions in switch statements are non-standard [-Wpedantic]
   21 |         case '0' ... '9':
      |         ^~~~
*/