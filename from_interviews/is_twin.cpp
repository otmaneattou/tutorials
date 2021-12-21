#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <boost/algorithm/string.hpp>

using namespace std;

bool is_twin(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    std::transform(s1.begin(), s1.end(), s1.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    std::transform(s2.begin(), s2.end(), s2.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    for (int idx{0}; idx < s1.size(); idx++)
    {
        if (s1[idx] != s2[idx])
            return false;
    }
    return true;
}

int main(int argc, const char **argv)
{
    string s1{"Markon"}, s2{"Romain"};
    bool result = is_twin(s1, s2);
    cout << result << endl;
    return 0;
}