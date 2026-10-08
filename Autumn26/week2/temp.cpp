#include <iostream>
#include <string>

int main()
{

    double temp_in, temp_out;
    std::string unit_in, unit_out;


    std::cin >> temp_in >> unit_in;
    // we don't print a prompt, we just read the input

    bool correct_unit = true;

    if(unit_in == "C" || unit_in == "c")
    {
        unit_out = "F";
        temp_out = (temp_in * 9/5) + 32;
    }
    else if (unit_in == "F" || unit_in == "f")
    {
        unit_out = "C";
        temp_out = ((temp_in - 32) * 5/9);
    }
    else
    {
        correct_unit = false;
    }

    if (correct_unit == true)
    {
        std::cout << temp_out << " " << unit_out << std::endl;
    }
    else
    {
         std::cout << "error, unit not recognised." << std::endl;
    }
}