#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    //create list of words to read

    std::ifstream infile;

    infile.open("word.txt");

    if(!infile.is_open())
    {
        std::cout << "File cannot be opened" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> compare_list;
    std::vector<int> tally;
    std::string temp;

    while (infile >> temp)
    {
        compare_list.push_back(temp);
        tally.push_back(0);
    }

    infile.close();

    std::ifstream textfile;

    textfile.open("text.txt");

    if(!textfile.is_open())
    {
        std::cout << "File cannot be opened" << std::endl;
        return EXIT_FAILURE;
    }

    std::string word;

    while(textfile >> word)
    {
        for (int i = 0; i < compare_list.size(); i++)
        {
            if (word == compare_list[i])
            {
                ++tally[i];
            }
        }
    }

    for (int i = 0; i < compare_list.size(); i++)
    {
        std::cout << compare_list[i] << ": " << tally[i] << std::endl;
    }
}