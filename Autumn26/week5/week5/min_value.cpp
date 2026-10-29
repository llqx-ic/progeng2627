#include <iostream>
#include <vector>



int min_vector_element(const std::vector<double>& vin)
{
    if (list.size() == 0)
    {
        return -1;
    }
    int index;
    double lowest_value = 10.0;

    for (int i = 0; i < vin.size(); ++i)
    {
        double temp = vin[i];
        if (temp < lowest_value)
        {
            index = i;
            lowest_value = temp;
        }
    }
    return index;
}

int main()
{
    std::vector<double> list{1.0,2.0,3.0,4.0};

    int expected = 0;

    if (min_vector_element(list) == 0)
    {
        std::cout << "1" << std::endl;
    }
}