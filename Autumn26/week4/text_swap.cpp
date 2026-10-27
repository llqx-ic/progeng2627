#include <iostream>

// this is the only different line:
void myswap(std::string& a, std::string& b){

    std::string tmp;
    tmp = a;
    a = b;
    b = tmp;

}

int main(){
    std::string n1, n2;

    std::cout << "please enter two strings" << std::endl;
    std::cin >> n1 >> n2;

    std::cout << "you entered:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;

    myswap(n1, n2);
    // here a becomes another name for n1
    // while b becomes another name for n2

    // it's just about the position/order in the parentheses:
    // n1 is passed to the first parameter (a)
    // n2 is passed to the second parameter (b)

    std::cout << "after swapping the values:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
}