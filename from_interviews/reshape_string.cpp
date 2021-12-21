#include <iostream>

#include <string>

using namespace std;

string reshape(string s, int n)
{
    string result = "";
    int counter = 0;
    for (int idx{0}; idx < s.size(); idx++)
    {
        if (counter % n == 0)
            result += "\n";
        if (s[idx] != ' ')
        {
            result += s[idx];
            counter++;
        }
    }
    return result;
}

int main()
{

    string s = "wajdi est enceinte";
    int n = 3;
    cout << reshape(s, n) << endl;
    return 0;
}