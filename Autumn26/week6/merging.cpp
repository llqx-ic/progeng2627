#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1
                        , const std::vector<int>& v2
                        , std::vector<int>& merged);

int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;
    std::vector<int> out;

    std::vector<int> expected_output;
    std::vector<int> expected_output_2;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};
        
    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }

    out.clear();

    v3 = {1,1,2,2,3,3};
    v4 = {2,2,4,5,6};
    expected_output_2 = {1,1,2,2,2,2,3,3,4,5,6};

    merge_vectors_int(v3, v4, out);

    if(out == expected_output_2){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}

void merge_vectors_int(const std::vector<int>& v1
                        , const std::vector<int>& v2
                        , std::vector<int>& merged)
{
    //read in v1
    for(auto it : v1)
    {
        merged.push_back(it);
    }
    
    int position_tracker = 0;
    for (int i = 0; i < v2.size(); ++i)
    {
        int temp = v2[i];

        for (int j = position_tracker; i < merged.size(); ++j)
        {
            if (temp < merged[j])
            {
                continue;
            }
            else if (temp == merged[j])
            {
                merged.insert(merged.begin() + j, temp);
                position_tracker = j;
                break;
            }
            else if (temp > merged[j] && temp < merged[j+1])
            {
                merged.insert(merged.begin() + (j + 1), temp);
                position_tracker = j + 1;
                break;
            }
            else if (temp > merged.back())
            {
                merged.push_back(temp);
                break;
            }
        }
    }
}