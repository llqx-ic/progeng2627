#include <iostream>

int collatz(int input, int count);

int main()
{
    //user input
    int user_input;

    std::cout << "Input number: \n";
    std::cin >> user_input;

    int count = 0;
    int max_value = user_input;

    int value = collatz(user_input, count);

    std::cout << "Steps: " << value << std::endl;

}

//recursive function
int collatz(int input, int count)
{    
    //base case(n==1)
    if (input == 1)
    {
        std::cout << input << " " << std::endl;
        return count;
    }
    //even
    else if ((input % 2) == 0)
    {
        ++count;
        std::cout << input << " ";
        return collatz(input / 2, count);
    }
    //odd
    else
    {
        ++count;
        std::cout << input << " ";
        return collatz(3*input + 1, count);
    }
}