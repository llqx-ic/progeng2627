#include <iostream>

int main()
{
    int input;

    std::cin >> input;


    for (int i = 1; i <= input; i++)
    {
        
        for (int j = 1; j < input + 1; j++)
        {
            std::cout << i * j << " ";
        }

        std::cout<< std::endl;
    }
}