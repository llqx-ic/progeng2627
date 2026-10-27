#include <iostream>
#include <vector>

int gcd(int a, int b);
int euler_totient(int n);
int totient_depth(int n, int& depth);
int local_depth_peak(int a, int b, int& x0, int& x1, int& x2);

int main()
{
    int x0;
    int x1;
    int x2;

    int a = local_depth_peak(14, 20, x0, x1, x2);
    
    std::cout << a << " " << x0 << " " << x1 << " " << x2 << std::endl;
}

int local_depth_peak(int a, int b, int& x0, int& x1, int& x2)
{
    std::vector<int> depth_values;

    //setting boundary
    int upper_bound;
    int lower_bound;

    if (a < b)
    {
        upper_bound = b;
        lower_bound = a;
    }
    else
    {
        upper_bound = a;
        lower_bound = b;
    }

    //filling the vector with depths
    for (int i = lower_bound; i <= upper_bound; ++i)
    {
        int depth = 0;
        int result = totient_depth(i, depth);
        depth_values.push_back(depth);
    }


    //finding peak depth and index;
    int peak_depth = 0;
    int index;
    bool local_peak = false;

    for (int i = 0; i < depth_values.size() ; ++i)
    {
        if (depth_values[i] > peak_depth)
        {
            peak_depth = depth_values[i];
            index = i;
        }

        if (i >= 2)
        {
            if (depth_values[i] > depth_values[i-1] && 
                depth_values[i] > depth_values[i + 1])
            {
                local_peak = true;
            }
        }
    }

    //check if local peak exist
    if(local_peak == true)
    {
        x0 = depth_values[index - 1];
        x1 = depth_values[index];
        x2 = depth_values[index + 1];
        return index + lower_bound;
    }
    else
    {
        x0 = 0;
        x1 = 0;
        x2 = 0;
        return -1;
    }
}


int totient_depth(int n, int& depth)
{
    int current_result = n;
    int sum = 0;

    while (current_result != 1)
    {
        current_result = euler_totient(current_result);
        sum += current_result;
        ++depth;
    }

    return sum;
}

int euler_totient(int n)
{
    int count = 0;

    for(int i = 1; i < n; ++i)
    {
        if (gcd(i, n) == 1)
        {
            ++count;
        }
    }

    return count;
}


int gcd(int a, int b)
{
    int dividend;
    int divisor;

    if (a < b)
    {
        dividend = b;
        divisor = a;
    }
    else
    {
        dividend = a;
        divisor = b;
    }

    int remainder = 1;

    while(remainder != 0)
    {
        remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }

    return dividend;
}