#include <iostream>

int main()
{
    double length;
    double breadth;

    std::cout << "What is your table length: \n";
    std::cin >> length;

    std::cout << "What is your table breadth: \n";
    std::cin >> breadth;

    double perimeter = 2*length + 2*breadth;

    double area = length * breadth;

    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;
}