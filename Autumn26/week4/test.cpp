#include <iostream>

int f(int n){
    int r = 0;
    if(n < 3){
        r = r + 1;
    }
    if((n % 2) == 0){
        r = r + 2;
    }
    return r;
}

int main()
{
    std::cout << f(2) << std::endl;
}