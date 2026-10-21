#include <iostream>

int main()
{
    int input;

    std::cout << "Enter a number: ";
    std::cin >> input;

    int sum = 1;

    for (int i = 1; i <= input ; ++i)
    {
        sum *= i;
    }

    std::cout << "Sum: " << sum << std::endl;
}