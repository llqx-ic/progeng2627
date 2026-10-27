#include <iostream>
#include <cmath>

double mypow(double base, int exponent);

int main()
{
    double x;
    int n;

    std::cout << "Input number and power: \n";
    std::cin >> x >> n;

    std::cout << "Result: " << mypow(x,n) << std::endl;

}

double mypow(double base, int exponent)
{
    double result = base;

    for (int i = 1 ; i < std::abs(exponent); ++i)
    {
        result = result * base;
    }

    if (exponent < 0)
    {
        result = 1 / result;
    }

    return result;
}