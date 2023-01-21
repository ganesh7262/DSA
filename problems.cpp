#include <stack>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    stack<char> stk;
    stk.push('g');
    cout << stk.top() << endl;

    return 0;
}
