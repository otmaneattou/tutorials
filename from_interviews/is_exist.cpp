#include <iostream>
#include <algorithm>

using namespace std;

bool is_exist(int ints[], int size, int k)
{
    if (binary_search(ints, ints + size, k))
        return true;
    return false;
}

int main()
{
    int ints[] = {-9, 14, 37, 102};
    cout << is_exist(ints, 4, 102) << endl;
    cout << is_exist(ints, 4, 36) << endl;
    return 0;
}
