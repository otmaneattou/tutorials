#include <iostream>

using namespace std;

class Algotithm
{
public:
    static int findLargest(int numbers[], int length)
    {
        int max = numbers[0];
        for (int i{1}; i < length; i++)
        {
            if (numbers[i] > max)
                max = numbers[i];
        }
        return max;
    }
};

int main()
{
    int numbers[4] = {1, 2, 3, 45};
    cout << Algotithm::findLargest(numbers, 4) << endl;
    return 0;
}