#include <iostream>
using namespace std;

class Box
{
private:
    int l, b, h;

public:
    Box()
    {
        l = b = h = 0;
    }

    Box(int length, int breadth, int height)
    {
        l = length;
        b = breadth;
        h = height;
    }

    Box(Box &B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }

    long long CalculateVolume()
    {
        return (long long)(l)*b * h;
    }

    bool operator<(Box &B)
    {
        // bool res = false;
        if (l == B.l && b == B.b && h < B.h)
            return true;

        else if (l == B.l && b < B.b)
            return true;

        else if (l < B.l)
            return true;

        return false;
    }

    friend ostream &operator<<(ostream &os, Box &A);
};
ostream &operator<<(ostream &os, Box &A)
{
    cout << A.l << " " << A.b << " " << A.h;
    return os;
}

int main()
{
    Box a = {1, 2, 7};
    Box b = {1, 2, 6};
    bool va = (a < b);
    // cout << a;
    cout << va;
    return 0;
}