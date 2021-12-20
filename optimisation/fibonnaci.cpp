#include <iostream>
#define TAILLE 100

using namespace std;

int fibTab[TAILLE];

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (fibTab[n] != -1)
        return fibTab[n];
    fibTab[n] = fib(n - 1) + fib(n - 2);
    return fibTab[n];
}

int main()
{
    for (int i{0}; i < TAILLE; i++)
    {
        fibTab[i] = -1;
    }
    int n;
    cout << "Give me an n: ";
    cin >> n;
    int result = fib(n);
    cout << endl
         << result << endl;
    return 0;
}