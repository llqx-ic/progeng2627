#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

void union_vector(const std::vector<std::string>& vin1
                  , const std::vector<std::string>& vin2
                  , std::vector<std::string>& vout);

void intersection_vector(const std::vector<std::string>& vin1
                         , const std::vector<std::string>& vin2
                         , std::vector<std::string>& vout);

int search_vector(std::string s, const std::vector<std::string>& vin);




int main()
{
    std::string file1_name;
    std::string file2_name;

    std::cout << "Enter name of first input file: ";
    std::cin >> file1_name;

    std::cout << "Enter name of second input file: ";
    std::cin >> file2_name;

    //read first file into vector one
    std::vector<std::string> input_one;

    std::ifstream infile1;
    
    infile1.open(file1_name);

    if (!infile1.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    std::string temp;

    while(infile1 >> temp)
    {
        input_one.push_back(temp);
    }

    infile1.close();

    //read second file into second vector
    std::vector<std::string> input_two;

    std::ifstream infile2;
    
    infile2.open(file2_name);

    if (!infile2.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    while(infile2 >> temp)
    {
        input_two.push_back(temp);
    }

    infile2.close();

    //union vector
    std::vector<std::string> union_vector_list;

    union_vector(input_one, input_two, union_vector_list);

    std::ofstream union_file;
    
    union_file.open("union.txt");
    
    if(!union_file.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < union_vector_list.size(); ++i)
    {
        union_file << union_vector_list[i] << std::endl;
    }

    union_file.close();

    //intersection vector
    std::vector<std::string> intersection_vector_list;

    intersection_vector(input_one, input_two, intersection_vector_list);

    std::ofstream intersection_file;
    
    intersection_file.open("intersection.txt");
    
    if(!intersection_file.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    for(int i = 0; i < intersection_vector_list.size(); ++i)
    {
        intersection_file << intersection_vector_list[i] << std::endl;
    }

    intersection_file.close();

    return 0;
}



void union_vector(const std::vector<std::string>& vin1
                  , const std::vector<std::string>& vin2
                  , std::vector<std::string>& vout)
{
    for (int i = 0; i < vin1.size(); ++i)
    {
        std::string temp = vin1[i];

        //exists in the union vector
        if (search_vector(temp, vout))
        {
            continue;
        }

        vout.push_back(temp);
    }

    for (int i = 0; i < vin2.size(); ++i)
    {
        std::string temp = vin2[i];

        //exists in the union vector
        if (search_vector(temp, vout))
        {
            continue;
        }

        vout.push_back(temp);
    }
    
}

void intersection_vector(const std::vector<std::string>& vin1
                         , const std::vector<std::string>& vin2
                         , std::vector<std::string>& vout)
{
    for (int i = 0; i < vin1.size(); ++i)
    {
        std::string temp = vin1[i];

        //doesnt exist in other file
        if (!search_vector(temp, vin2))
        {
            continue;
        }

        //exists in intersection vector
        if (search_vector(temp, vout))
        {
            continue;
        }

        vout.push_back(temp);
    }
}

int search_vector(std::string s, const std::vector<std::string>& vin)
{
    for(const auto& it : vin)
    {
        if (s == it)
        {
            return 1;
        }
    }

    return 0;
}