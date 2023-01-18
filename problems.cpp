#include <string>
#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string res;
        long long int N, K, D;
        cin >> N >> K;
        while (N--)
        {
            cin >> D;
            if (D % K == 0)
                res = res + '1';
            else
                res = res + '0';
        }
        cout << res << endl;
    }
    return 0;
}
