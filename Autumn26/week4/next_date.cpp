#include <iostream>

bool leap_year(int year);
void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2);

bool leap_year(int year){
    bool ly;

    if( (year % 4) == 0){ 
        // if multiple of 4

        if( (year % 100) == 0){ 
            // if (also) multiple of 100
            if ((year % 400) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            // ...

        }
        else{ 
            // if not multiple of 100
            // (but still multiple of 4)
            return true;
            // ...

        }
    }
    else{
        // if not multiple of 4
        return false;
    }

    return ly;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    // TODO: d1, m1, y1 are inputs 
    // corresponding to the date d1/m1/y1
    // d2, m2, y2 are outputs that the function must compute
    // corresponding to the date d2/m2/y2 
    // which is meant to be the day after d1/m1/y1

    // function leap_year is useful for this task

    // do not begin to write code straightaway
    // sketch some diagrams first like we did
    // for the leap year task

    // (this function should not print anything)

    if (d1 == 28)
    {
        if (m1 == 2)
        {
            //leap year, add 1 to day
            if (leap_year(y1) == true)
            {
                d2 = d1 + 1;
                m2 = m1;
                y2 = y1;
            }
            else
            {
                d2 = 1;
                m2 = m1 + 1;
                y2 = y1;
            }
            //not leap year, day goes to first, month change
        
        }
        else
        {
            d2 = d1 + 1;
            m2 = m1;
            y2 = y1;
        }
    }
    else if (d1 == 29)
    {
        d2 = 1;
        m2 = m1 + 1;
        y2 = y1;
    }
    else if (d1 == 30)
    {   
        //new month
        if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
        {
            d2 = 1;
            m2 = m1 + 1;
            y2 = y1;
        }
        else
        {
            d2 = d1 + 1;
            m2 = m1;
            y2 = y1;
        }
    }
    else if (d1 == 31)
    {
        if (m1 == 12)
        {
            d2 = 1;
            m2 = 1;
            y2 = y1 + 1;
        }
        else
        {
            d2 = 1;
            m2 = m1 + 1;
            y2 = y1;
        }
    }
    else
    {
        d2 = d1 + 1;
        m2 = m1;
        y2 = y1;
    }
    
}

int main(){
    // TODO: write a main to test the function
    int d2;
    int m2;
    int y2;

    next_date(29, 2, 1900, d2, m2, y2);

    if (d2 == 1 && m2 == 3 && y2 == 1900)
    {
        std::cout << "1" << std::endl;
    }
    
}