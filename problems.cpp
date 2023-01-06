#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string s = "ganesh";
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        stack.push(s[i]);
    }

    char *res = new char[sizeof(s) / sizeof(s[0])];
    for (int i = 0; i < s.size(); i++)
    {
        res[i] = stack.top();
        stack.pop();
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
