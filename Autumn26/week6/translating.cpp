#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main()
{
    //write word meanings to key & value vectors
    std::ifstream infile;
    
    infile.open("meaning.txt");

    if (!infile.is_open())
    {
        std::cout << "File cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    std::string temp;

    std::vector<std::string> key;
    std::vector<std::string> value;

    int counter = 0;

    while(infile >> temp)
    {
        if (counter % 2 == 0)
        {
            key.push_back(temp);
            ++counter;
        }
        else
        {
            value.push_back(temp);
            ++counter;
        }
    }

    infile.close();

    //opening text
    std::ifstream text;

    text.open("ad.txt");

    if (!text.is_open())
    {
        std::cout << "File cannot be opened." << std::endl;
        return EXIT_FAILURE;
    }

    //rewriting ad
    std::vector<std::string> output;

    while (text >> temp)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            //has other meaning
            if (temp == key[i])
            {
                output.push_back(value[i]);
                break;
            }
            //no other meaning
            if (i == key.size() - 1)
            {
                output.push_back(temp);
            }
        }
    }
    
    text.close();

    //open output
    std::ofstream outfile;

    outfile.open("rewritten_ad.txt");

    if (!outfile.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < output.size(); i++)
    {
        outfile << output[i] << " ";
    }

    outfile.close();
}