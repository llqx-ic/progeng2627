// first version, not the most efficient one
#include <iostream>

int main(){
    int n;
    bool found_factor = false;
    // initially we haven't found any factors...

    std::cout << "please enter an integer greater than 1" << std::endl;
    // we assume that the user enters an integer greater than 1
    std::cin >> n;


    // cf like candidate factor
    // (begins at 2, smallest candidate factor)

    for(int cf = 2; cf < n; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...

            std::cout << "the number is not prime";
            return 0;
        }

    }

    std::cout << "the number is prime" << std::endl;
}