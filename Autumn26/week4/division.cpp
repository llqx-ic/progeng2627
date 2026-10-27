#include <iostream>

double division(int a, int b, double& remainder);

int main()
{
    int a = 5;
    int b = 2;
    double remainder;

    double result = division(a, b, remainder);

    if (result == 2.5 && remainder == 0.5)
    {
        std::cout << "1" << std::endl;
    }

}

double division(int a, int b, double& remainder)
{
    double result = (float)a / (float)b;
    remainder = result - static_cast<int>(result);

    return result;
}