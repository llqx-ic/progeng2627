#include <iostream>

int main()
{
    int upper_limit;

    std::cout << "Highest number: ";
    std::cin >> upper_limit;

    int lower_limit;

    std::cout << "Lower_limit: ";
    std::cin >> lower_limit;
    
    int user_number;

    while (true)
    {
        std::cout << "Number: ";
        std::cin >> user_number;

        if (user_number <= upper_limit && user_number >= lower_limit)
        {
            break;
        }
        
        std::cout << "Number not within range" << std::endl;

    }

    int guessed_number;
    int upper_guess = upper_limit;
    int lower_guess = lower_limit; 

    std::string user_yesno;
    std::string user_higherlower;

    bool correct_number = false;


    /*1: make a guess(half of range)
    2: send guess back to user
    3: user sends back YES or NO if its correct number
    4: if correct update correct number bool, end
    5: if not ask for higher lower
    6: if higher, half of upper to guessed number
    7: if lower,  half of lower to guessed number
    8: repeat*/

    while(correct_number != true)
    {
        guessed_number = ((upper_guess - lower_guess)/2 + lower_guess);

        std::cout << "Is your number: " << guessed_number << " yes/no" << std::endl;
        std::cin >> user_yesno;

        if (user_yesno == "yes")
        {
            correct_number = true;
            break;
        }

        std::cout << "Is your number higher or lower? \n";
        std::cin >> user_higherlower;

        if (user_higherlower == "higher")
        {
            lower_guess = guessed_number;
        }
        else
        {
            upper_guess = guessed_number;
        }
    }
    
    std::cout << "Your number is " << guessed_number << std::endl;

    return 0;
}