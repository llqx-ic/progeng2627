#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

std::vector<unsigned long> catalan_numbers(int n);

int main()
{
    std::ifstream infile {"expressions.txt"};

    if (!infile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    //writing each line to a vector
    std::vector<std::string> input_line;

    std::string temp;

    while (std::getline(infile, temp))
    {
        input_line.push_back(temp);
    }

    infile.close();

    //number of operators in line
    std::vector<unsigned long> catalan_value;
    for (auto it : input_line)
    {
        int operator_sum = 0;
        for (int i = 0; i < it.size(); ++i)
        {
            char c = it[i];
            if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                ++operator_sum;
            }
        }

        std::vector<unsigned long> catalan_list = catalan_numbers(operator_sum);

        catalan_value.push_back(catalan_list[operator_sum]);
    }

    std::ofstream outfile {"expression_counts.txt"};

    if(!outfile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < input_line.size(); ++i)
    {
        outfile << input_line[i] << "   ";
        outfile << catalan_value[i] << "\n";
    }

    outfile.close();

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