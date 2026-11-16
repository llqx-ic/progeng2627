#include <iostream>
#include <string>
#include <vector>

// for std::pair
#include <utility>

bool is_palindrome(std::string s){
    std::string s_no_whitespace;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        s_no_whitespace.push_back(s[i]);
    }

    std::string s_reverse;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        s_reverse.push_back(s[i]);
    }

    if (s_reverse == s_no_whitespace)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

    std::vector<std::pair<std::string, bool>> test_cases = 
    {
        {"a man a plan a canal panama", true}, 
        {"a man plan a canal panama", false},
        {"a toyota", true},
        {"never odd or even", true},
        {"never even or odd", false}
    };

    for(int i = 0; i < test_cases.size(); i++){
        // each variable of type std::pair has two fields called first and second

        bool test = is_palindrome(test_cases[i].first);

        if(test == test_cases[i].second){
            std::cout << "passed" << std::endl;
        }
        else{
            std::cout << "FAILED" << std::endl;
            std::cout << test_cases[i].first << std::endl;
            std::cout << "expected: " << test_cases[i].second << std::endl;
            std::cout << "got: " << test << std::endl;
        }
    }
}