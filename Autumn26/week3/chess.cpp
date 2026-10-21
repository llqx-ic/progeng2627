#include <iostream>

bool check_knight(int x_1, int y_1, int x_2, int y_2);
bool check_bishop(int x_1, int y_1, int x_2, int y_2);
bool check_rook(int x_1, int y_1, int x_2, int y_2);
bool check_king(int x_1, int y_1, int x_2, int y_2);
bool check_bounds(int x_2, int y_2);


int main()
{
    //get piece, origin and destination
    std::string piece;

    int x_origin;
    int y_origin;

    int x_destination;
    int y_destination;


    std::cout << "Choose piece: \n";
    std::cin >> piece;

    std::cout << "Starting location: x y \n";
    std::cin >> x_origin >> y_origin;

    std::cout << "Destination location: x y \n";
    std::cin >> x_destination >> y_destination;

    if (piece == "Knight" || piece == "knight")
    {
        bool possible_move = check_knight(x_origin, y_origin, x_destination, y_destination);
        if (possible_move == true)
        {
            std::cout << "Valid move" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid move" << std::endl;
            return 1;
        }
    }

    if (piece == "Bishop" || piece == "bishop")
    {
        bool possible_move = check_bishop(x_origin, y_origin, x_destination, y_destination);
        if (possible_move == true)
        {
            std::cout << "Valid move" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid move" << std::endl;
            return 1;
        }
    }

    if (piece == "Rook" || piece == "rook")
    {
        bool possible_move = check_rook(x_origin, y_origin, x_destination, y_destination);
        if (possible_move == true)
        {
            std::cout << "Valid move" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid move" << std::endl;
            return 1;
        }
    }

    if (piece == "Queen" || piece == "queen")
    {
        bool possible_move = check_bishop(x_origin, y_origin, x_destination, y_destination);
        if (possible_move != true)
        {
            possible_move = check_rook(x_origin, y_origin, x_destination, y_destination);

            if (possible_move == true)
            {
                std::cout << "Valid move" << std::endl;
                return 0;
            }
            else
            {
                std::cout << "Invalid move" << std::endl;
                return 1;
            }
        }
        else
        {
            std::cout << "Valid move" << std::endl;
            return 0;
        }
    }

    if (piece == "King" || piece == "king")
    {
        bool possible_move = check_king(x_origin, y_origin, x_destination, y_destination);
        if (possible_move == true)
        {
            std::cout << "Valid move" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid move" << std::endl;
            return 1;
        }
    }

}

bool check_king(int x_1, int y_1, int x_2, int y_2)
{
    if (check_bounds(x_2, y_2) != true)
    {
        return false;
    }

    int x_change = x_1 - x_2;

    //y_change(+ve down, -ve up)
    int y_change = y_1 - y_2;

    if (x_change == 1 || x_change == -1 || x_change == 0)
    {
        if (y_change == 0 && x_change == 0)
        {
            return false;
        }
        else if (y_change == -1 || y_change == 1 || y_change == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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

bool check_bishop(int x_1, int y_1, int x_2, int y_2)
{
    if (check_bounds(x_2, y_2) != true)
    {
        return false;
    }

    //x change (+ve left, -ve right)
    int x_change = x_1 - x_2;

    //y_change(+ve down, -ve up)
    int y_change = y_1 - y_2;

    if (x_change == y_change || x_change == (-1 * y_change))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_rook(int x_1, int y_1, int x_2, int y_2)
{
    if (check_bounds(x_2, y_2) != true)
    {
        return false;
    }

    int x_change = x_1 - x_2;

    //y_change(+ve down, -ve up)
    int y_change = y_1 - y_2;

    if (x_change != 0 && y_change == 0)
    {
        return true;
    }
    else if (y_change != 0 && x_change == 0)
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