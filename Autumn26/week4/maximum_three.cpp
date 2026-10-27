#include <iostream>

int maximum(int a, int b, int c);

int main()
{
    int a;
    int b;
    int c;

    std::cout << "Enter 3 numbers: \n";
    std::cin >> a >> b >> c;

    std::cout << "Maximum: " << maximum(a,b,c);

    return 0;

}

int maximum(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    
    if (b > a && b > c)
    {
        return b;
    }

    if (c > a && c > b)
    {
        return c;
    }
    else
    {
        return 0;
    }
}