#include <iostream>
#include <vector>

int search_vector(int n, const std::vector<int>& vin)
{
    for(int i = 0; i < vin.size(); i++)
    {
        int temp = vin[i];
        int index;
        if (temp == n)
        {
            index = i;
            return index;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> list{1,2,3,4,5};

    if(search_vector(6, list) == -1)
    {
        std::cout << "1" << std::endl;
    }

    if (search_vector(3, list) == 2)
    {
        std::cout << "1" << std::endl;
    }

}