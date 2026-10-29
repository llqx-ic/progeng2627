#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin,
             double t, std::vector<double>& vout)
{
    for (auto it : vin)
    {
        if (it < t)
        {
            vout.push_back(it);
        }
    }
}

int main()
{
    std::vector<double> vin{1.0,2.0,3.0,4.0,5.0,6.0};
    std::vector<double> vout;

    double t = 5.0;

    filter_v(vin, t, vout);

    for(int i = 0; i < vout.size(); ++i)
    {
        std::cout << vout[i] << std::endl;
    }
}