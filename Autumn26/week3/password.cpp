#include <iostream>

//aim is to implement iphone password attemps before being locked out

int main()
{
    int password;
    
    std::cout << "What is your 4 digit password: \n";
    std::cin >> password;

    int attempt_count = 0;

    while (attempt_count < 5)
    {
        int password_attempt; 
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Input password: \n";
            std::cin >> password_attempt;

            if (password_attempt == password)
            {
                std::cout << "Correct password." << std::endl;
                return 0;
            }
            else
            {
                std::cout << "Wrong password \n";
                ++attempt_count;
            }
        }
    }

    std::cout << "Too many attempts, locked out";
    return 0;
}