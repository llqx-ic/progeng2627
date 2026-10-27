#include <iostream>

void rectangle(double length, double breadth
                , double& area, double& perimeter);

int main()
{
    double length = 10.5;
    double breadth = 15;

    double area;
    double perimeter;

    rectangle(length, breadth, area, perimeter);
    
    if (area == 157.5 && perimeter == 51)
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << " " << std::endl;
    }

}

void rectangle(double length, double breadth
                , double& area, double& perimeter)
{
    area = length * breadth;
    perimeter = 2*length + 2*breadth;
}