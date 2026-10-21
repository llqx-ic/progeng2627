#include <iostream>
#include <cmath>


int perimeter(int a, int b, int c);
double heron(int a, int b, int c, int perimeter);


int main()
{
    int a;
    int b;
    int c;

    std::cout << "input 3 numbers: \n";
    std::cin >> a >> b >> c;

    if (!(a + b > c) || !(a + c > b) || !(b + c > a))
    {
        std::cout << "invalid" << std::endl;
        return 0;
    }

    if (a == b && a == c && b == c)
    {
        std::cout << "equilateral" << std::endl;
        int triangle_perimeter = perimeter(a,b,c);
        std::cout << "Perimeter: " << triangle_perimeter << std::endl;
        std::cout << "Area: " << heron(a,b,c,triangle_perimeter) << std::endl;
        return 0;
    }

    if (a == b && a != c)
    {
        std::cout << "iscosceles" << std::endl;
        int triangle_perimeter = perimeter(a,b,c);
        std::cout << "Perimeter: " << triangle_perimeter << std::endl;
        std::cout << "Area: " << heron(a,b,c,triangle_perimeter) << std::endl;
        return 0;
    }

    if (a == c && a != b)
    {
        std::cout << "iscosceles" << std::endl;
        int triangle_perimeter = perimeter(a,b,c);
        std::cout << "Perimeter: " << triangle_perimeter << std::endl;
        std::cout << "Area: " << heron(a,b,c,triangle_perimeter) << std::endl;
        return 0;
    }

    if (c == b && a != c)
    {
        std::cout << "iscolsceles" << std::endl;
        int triangle_perimeter = perimeter(a,b,c);
        std::cout << "Perimeter: " << triangle_perimeter << std::endl;
        std::cout << "Area: " << heron(a,b,c,triangle_perimeter) << std::endl;
        return 0;
    }

    std::cout << "scalene" << std::endl;
    int triangle_perimeter = perimeter(a,b,c);
    std::cout << "Perimeter: " << triangle_perimeter << std::endl;
    std::cout << "Area: " << heron(a,b,c,triangle_perimeter) << std::endl;
    return 0;
}

int perimeter(int a, int b, int c)
{
    int sum = a + b + c;
    return sum;
}

double heron(int a, int b, int c, int perimeter)
{
    double s = perimeter / 2.0;

    double inner = s*(s-a)*(s-b)*(s-c);
    double area = std::sqrt(inner);
    return area;
}