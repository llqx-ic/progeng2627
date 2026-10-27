#include <iostream>

// function myswap to be used 
// in sort_two_numbers below
// must be included here (beforehand)
void sort_three_numbers(double& s1, double& s2, double& s3);
void myswap(double& a, double& b);


int main(){
    double n1 = 1;
    double n2 = 1.4;
    double n3 = 3.2;
    sort_three_numbers(n3, n2, n1);
    
    if (n3 == 1 && n2 == 1.4 && n1 == 3.2)
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }
}

void sort_three_numbers(double& s1, double& s2, double& s3)
{
    if (s1 > s2)
    {
        myswap(s1,s2);
    }
    if (s2 > s3)
    {
        myswap(s2,s3);
        myswap(s2,s1);
    }
}


void myswap(double& a, double& b)
{

    double tmp;
    tmp = a;
    a = b;
    b = tmp;

}