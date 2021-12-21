#include <string>
//#include "AsciiArt.h"
// Ce code ne marche pas à cause  de la non-existance de cette librairie
// TODO:  install AscciArt.h
using namespace std;

char scanChar(string str)
{
    for (char car{'A'}; car <= 'Z'; car++)
    {
        if (AsciiArt::printChar(car) == str)
        {
            return car;
        }
        return '?';
    }
}

int main(int argc, const char **argv)
{
    string str{AsciiArt::printChar('B')};
    std::cout << str << std::endl;
    std::cout << scanChar(str) << std::endl;
    return 0;
}