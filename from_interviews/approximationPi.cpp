#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    double x;
    double y;
} Point;

class Pi
{

public:
    static double approx(vector<Point> &pts)
    {
        int compteur{0};
        for (int idx{0}; idx < pts.size(); idx++)
        {
            double x = pts[idx].x;
            double y = pts[idx].y;
            if (x <= 1 && x >= 0 && y <= 1 && y >= 0 && x * x + y * y <= 1)
                compteur++;
        }
        double pi = 4 * (compteur / 1.0) / pts.size();
        return pi;
    }
};

int main()
{
    vector<Point> a{Point{5, 10}, Point{10, 10.5}};
    cout << Pi::approx(a) << endl;
    return 0;
}
