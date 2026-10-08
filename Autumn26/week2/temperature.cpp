#include <iostream>

int main()
{
    double temp_c;

    std::cout << "Temperature in celsius: \n";
    std::cin >> temp_c;


    double temp_f = (temp_c * 1.8) + 32;
    std::cout << "The temperature is " << temp_f << std::endl;

    return 0;

}