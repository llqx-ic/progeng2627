#include <iostream>
#include <cmath>

double mypow(double base, int exponent);
double sum(double base, int exponent);

int main()
{
    double x;
    int n;

    std::cout << "Input number and power: \n";
    std::cin >> x >> n;

    double result = sum(x,n);

    std::cout << "Result: " << result << std::endl;

}

double sum(double base, int exponent)
{
    double sum = 0;

    for (int i = 1; i <= exponent ; ++i)
    {
        sum += mypow(base, i);
    }

    return sum;
}

double mypow(double base, int exponent)
{
    double result = base;

    for (int i = 1 ; i < std::abs(exponent); ++i)
    {
        result = result * base;
    }

    return result;
}