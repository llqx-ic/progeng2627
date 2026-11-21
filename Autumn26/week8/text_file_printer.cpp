#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Include your text file \n";
    }

    std::ifstream infile {argv[1]};

    if (!infile.is_open())
    {
        std::cout << "Cannot open text file." << std::endl;
    }

    std::string temp;

    while (infile >> temp)
    {
        std::cout << temp << " ";
    }

    infile.close();

    return 0;
}