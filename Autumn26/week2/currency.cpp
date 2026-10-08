#include <iostream>

int main()
{
    double gbp;
    double eur_exchange = 1.18;

    std::cout << "Amount of GBP: \n";
    std::cin >> gbp;


    double eur = gbp*eur_exchange;
    std::cout << "You have: " << eur << "Euros" << std::endl;

    return 0;
}