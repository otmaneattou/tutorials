#include <iostream>
#include <stdexcept>

using namespace std;

double *divide(int &a, int &b)
{
    if (b == 0)
    {
        throw invalid_argument("the second value must be different to zero");
    }
    if ((int)a < INT16_MIN || (int)b < INT16_MIN || (int)a > INT16_MAX || (int)b > INT16_MAX)
    {
        throw invalid_argument("the values must be less than INT16_MAX and more than INT16_MIN ");
    }

    return new double{(double)a / b};
}
