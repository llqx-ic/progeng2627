#include <iostream>

int main()
{
    int number;

    std::cout << "Number: \n";
    std::cin >> number;

    if (number % 3 == 0)
    {
        std::cout << number << " is a multiple of 3." << std::endl;
    }
    else
    {
        std::cout << number << " is not a multiple of 3." << std::endl;
    }

    return 0;
}