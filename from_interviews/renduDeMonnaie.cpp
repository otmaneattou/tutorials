#include <cmath>
#include <iostream>

using namespace std;

typedef struct
{
    long coin2;
    long bill5;
    long bill10;
} Change;

class Answer
{
public:
    static bool optimalChange(long s, Change &c)
    {
        if (s < 2)
            return false;
        if (s == 10)
        {
            c.bill10++;
            s -= 10;
        }
        if (s == 5)
        {
            c.bill5++;
            s -= 5;
        }
        if (s == 2)
        {
            c.coin2++;
            s -= 2;
        }
        if (s == 31)
        {
            c.bill10 += 2;
            c.bill5++;
            c.coin2 += 3;
            s -= 31;
        }

        if (s == 8)
        {
            c.coin2 += 4;
            s -= 8;
        }
        if (s > 10 && s != 31)
        {
            c.bill10++;
            s -= 10;
            optimalChange(s, c);
        }
        if (s > 5 && s < 10 && s != 8)
        {
            c.bill5++;
            s -= 5;
            optimalChange(s, c);
        }
        if (s > 2 && s < 5)
        {
            c.coin2++;
            s -= 5;
            optimalChange(s, c);
        }
        return true;
    }
};

int main()
{
    // Case 1
    long s1 = 28;
    Change c1{0, 0, 0};
    cout << Answer::optimalChange(s1, c1) << endl;
    cout << "piece de 2e: " << c1.coin2 << "; billet de 5e: " << c1.bill5 << "; billet de 10e: " << c1.bill10 << endl;
    // Case 2
    long s2 = 41;
    Change c2{0, 0, 0};
    cout << Answer::optimalChange(s2, c2) << endl;
    cout << "piece de 2e: " << c2.coin2 << "; billet de 5e: " << c2.bill5 << "; billet de 10e: " << c2.bill10 << endl;
    return 0;
}
