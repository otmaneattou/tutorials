// From https://www.udemy.com/course/patterns-cplusplus/learn/lecture/7736714#overview
#include <iostream>
#include <cmath>

using namespace std;

enum class PointType
{
    cartesian,
    polar
};

class Point
{
public:
    friend class PointFactory;
    Point(float x, float y) : x(x), y(y){};
    float x, y;

    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x:  " << point.x << " y:  " << point.y;
        return os;
    }
};

struct PointFactory
{
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }
    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main()
{
    auto p = PointFactory::NewPolar(5, M_PI_4);
    cout << p << endl;
    return 0;
}
