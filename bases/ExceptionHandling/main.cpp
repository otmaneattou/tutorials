#include "divide.cpp"

using namespace std;

int main(int argc, const char **argv)
{

    int x{50};
    int y{120};
    double *z;
    try
    {
        z = divide(x, y);
        std::cout << "The result is: " << *z << std::endl;
    }
    catch (invalid_argument &e)
    {
        std::cout << "The error is " << e.what() << '\n';
    }

    return 0;
}