#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


std::vector<double> row_vector(std::string s);

std::vector<std::vector<double>> 
construct_matrix(std::string input_file);

std::vector<std::vector<double>> matrix_multiplication(
    std::vector<std::vector<double>> m1,
    std::vector<std::vector<double>> m2);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> matrix1 = construct_matrix(argv[1]);
    std::vector<std::vector<double>> matrix2 = construct_matrix(argv[2]);

    std::vector<std::vector<double>> result_matrix = 
    matrix_multiplication(matrix1, matrix2);

    for (const auto& row : result_matrix)
    {
        for (double value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;

        
}


std::vector<double> row_vector(std::string s)
{
    std::vector<double> row;
    std::stringstream temp_string(s);

    double temp_double;
    while (temp_string >> temp_double)
    {
        row.push_back(temp_double);
    }

    return row;
}

std::vector<std::vector<double>> 
construct_matrix(std::string input_file)
{
    std::vector<std::vector<double>> matrix;

    std::ifstream infile {input_file};

    if(!infile.is_open())
    {
        std::cout << "File could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    while(std::getline(infile,line))
    {
        matrix.push_back(row_vector(line));
    }

    infile.close();

    return matrix;
}

std::vector<std::vector<double>> matrix_multiplication(
    std::vector<std::vector<double>> m1,
    std::vector<std::vector<double>> m2)
{
    std::vector<std::vector<double>> result_matrix;

    for(size_t i = 0; i < m1.size(); ++i)
    {
        std::vector<double> row;

        for(size_t j = 0; j < m2[0].size(); ++j)
        {
            //row
            double sum = 0;
            for(size_t k = 0; k < m2.size(); ++k)
            {
                sum +=  m1[i][k] * m2[k][j];
            }
            row.push_back(sum);
        }
        result_matrix.push_back(row);
    }

    return result_matrix;
}