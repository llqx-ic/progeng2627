#include <iostream>
#include <vector>

std::vector<unsigned long> catalan_numbers(int n);

int main()
{
    int n;

        std::cout << "Enter n: ";
        std::cin >> n;

        std::vector<unsigned long> numbers = catalan_numbers(n);

        for (int i = 0; i < numbers.size(); i++) {
            std::cout << "C" << i << " = " << numbers[i] << std::endl;
        }

        return 0;
}

std::vector<unsigned long> catalan_numbers(int n)
{
    std::vector<unsigned long> catalan;

    catalan.push_back(1);

    for (int i = 0; i < n; ++i)
    {
        unsigned long sum = 0;

        for (int j = 0; j <= i; ++j)
        {
            sum += (catalan[j])*(catalan[i - j]);
        }

        catalan.push_back(sum);
    }
    return catalan;
}