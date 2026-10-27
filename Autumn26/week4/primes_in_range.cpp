#include <iostream>

void prime_numbers(int a, int b);
int smallest_factor(int n);

int main()
{
    int a;
    int b;

    std::cout << "Input 2 numbers: a b, a < b\n";
    std::cin >> a >> b;

    prime_numbers(a,b);

    return 0;
}
   

void prime_numbers(int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        int result = smallest_factor(i);

        if (result == 0)
        {
            continue;
        }
        
        if (result < a)
        {
            continue;
        }

        std::cout << result << std::endl;
    }
}
   
int smallest_factor(int n)
{
    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            return 0;
        }
    }
    return n;
}
