#include <iostream>
#include <vector>

int main() {
    int num = 250;
    int base = 16;
    std::vector<int> digits;

    /// Construct several more test cases
    /// using different values of num and base

    if (digits_in_base(num, base, digits)) {
        print_digits_as_number(digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}

bool number_string