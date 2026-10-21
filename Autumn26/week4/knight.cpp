#include <iostream>
#include <cstdlib>
#include <ctime>

bool check_knight(int x_1, int y_1, int x_2, int y_2);
bool check_win(int x_2, int y_2);
bool check_bounds(int x_2, int y_2);

int main()
{
    // Seed the random number generator
    std::srand(std::time(NULL));

    // Generate random coordinates from 2 to 7
    int row = std::rand() % 6 + 2;
    int col = std::rand() % 6 + 2;

    int x_origin = row;
    int y_origin = col;

    int x_destination;
    int y_destination;

    int counter = 0;
    
    bool win = false;

    while(win != true)
    {
        if (counter > 5)
        {
            x_origin = row;
            y_origin = col;

            std::cout << "Try again, win in 5 moves or less." << std::endl;
        }

        //display position
        std::cout << "Position: " << x_origin << " " << y_origin << "\n";

        std::cout << "Move: x y \n";
        std::cin >> x_destination >> y_destination;
        
        if (check_knight(x_origin, y_origin, x_destination, y_destination) == true)
        {
            x_origin = x_destination;
            y_origin = y_destination;

            ++counter;

            win = check_win(x_origin, y_origin);
        }
        else
        {
            std::cout << "Invalid move. " << std::endl;
        }
        
    }

    std::cout << "You have won in " << counter << " steps" << std::endl;

}

bool check_knight(int x_1, int y_1, int x_2, int y_2)
{
    if (check_bounds(x_2, y_2) != true)
    {
        return false;
    }

    //x change (+ve left, -ve right)
    int x_change = x_1 - x_2;

    //y_change(+ve down, -ve up)
    int y_change = y_1 - y_2;

    if (y_change == -2 || y_change == 2)
    {
        if (x_change == -1 || x_change == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (y_change == -1 || y_change == 1)
    {
        if (x_change == -2 || x_change == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool check_win(int x_2, int y_2)
{
    if ((x_2 == 1 && y_2 == 8) || (x_2 == 1 && y_2 == 1) 
        || (x_2 == 8 && y_2 == 1) || (x_2 == 8 && y_2 == 8))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_bounds(int x_2, int y_2)
{
    if (x_2> 9 || x_2 < 0)
    {
        return false;
    }
    else if (y_2 > 9 || y_2 < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}