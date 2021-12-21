#include <iostream>
using namespace std;

int bit_value(int n, int pos)
{
    string r;
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }

    cout << r << endl;

    int bit = (int)r[pos] - 48;

    return bit;
}

int main()
{
    cout << bit_value(5, 2) << endl;
    return 0;
}