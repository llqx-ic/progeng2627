#include <iostream>
#include <cmath>

int main()
{
    double weight;
    double height;

    std::cout << "What is your weight: \n";
    std::cin >> weight;

    std::cout << "What is your height: \n";
    std::cin >> height;

    double bmi = (std::round(10 * (weight / (height*height))) / 10);


    std::cout << "Your bmi is " << bmi << std::endl;

    return 0;

}