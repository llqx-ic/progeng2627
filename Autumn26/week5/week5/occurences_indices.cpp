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

    int count = 0;
    int num_match;

    std::cout << "Enter a number: \n";
    std::cin >> num_match;

    std::vector<int> indices;

    for (int i = 0; i < list.size(); ++i)
    {
        int temp = list[i];
        if (temp == num_match)
        {
            ++count;
            indices.push_back(temp);
        }
    }

    std::cout << "There are " << count << " occurences of " 
    << num_match << std::endl;

    for (auto it : indices)
    {
        std::cout << it << std::endl;
    }

    return 0;
}