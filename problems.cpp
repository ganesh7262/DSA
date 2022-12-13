#include <math.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 1)
            return true;
        if (n > 0 && n % 2 == 0)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    cout << log2(3) << endl;
    cout << pow(2, log2(3)) << endl;
    return 0;
}
