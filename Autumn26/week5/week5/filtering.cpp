#include <iostream>
#include <vector>

int main()
{
    int vec_length;
    
    std::cout << "Length of vector: \n";
    std::cin >> vec_length;

    std::vector<int> list;

    for(int i = 0; i < vec_length; i++)
    {
        int temp;
        std::cout << "Enter number: ";
        std::cin >> temp;

        list.push_back(temp);
    }

    int limit;

    std::cout << "Enter a number: ";
    std::cin >> limit;

    for(auto it : list)
    {
        if (it < limit)
        {
            std::cout << it << std::endl;
        }
    }

    return 0;
}