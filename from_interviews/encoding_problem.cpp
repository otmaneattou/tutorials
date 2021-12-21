#include <iostream>
#include <string>
#include <map>

using namespace std;

string encoding(string s)
{
    map<string, int> matching;
    string result;
    for (int idx{0}; idx < s.size(); idx++)
    {
        string carac{s[idx]};
        if (matching.find(carac) != matching.end())
        {
            matching[carac] += 1;
        }
        else
        {
            matching[carac] = 1;
        }
    }
    for (auto kv : matching)
    {
        auto &key = kv.first;
        auto &value = kv.second;
        result += std::to_string(value) + key;
    }
    return result;
}

int main(int argc, const char **argv)
{
    string s{"motdepasse"};
    cout << s << endl;
    cout << encoding(s) << endl;
    return 0;
}