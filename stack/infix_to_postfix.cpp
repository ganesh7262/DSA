#include <iostream>
#include <stack>
using namespace std;

bool IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '/' || x == '*')
        return true;
    return false;
}

int Precidence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else
        return 2;
    return 0;
}
void Display(char *x, int siz)
{
    for (int i = 0; i < siz; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

char *ExpConvert(char *exp, int siz)
{
    stack<char> stk;
    int k = 0;
    char *res = new char[10];

    for (int i = 0; i < siz; i++)
    {
        if (IsOperand(exp[i]))
        {
            while (!stk.empty() && (Precidence(stk.top()) >= Precidence(exp[i])))
            {
                res[k++] = stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
        else
        {
            res[k++] = exp[i];
        }
    }
    while (!stk.empty())
    {
        res[k++] = stk.top();
        stk.pop();
    }
    return res;
}

int main()
{
    char *exp = "a+b*c-d/e";
    int siz = 10;
    char *res = ExpConvert(exp, siz);
    Display(res, siz);
    return 0;
}