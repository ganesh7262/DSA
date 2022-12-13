#include <iostream>
using namespace std;
// in tridagonal matrix abs(i-j)<=1
/*
    11  12  0   0   0
    21  22  23  0   0
    0   32  33  34  0
    0   0   43  44  45
    0   0   0   54  55
*/
// No of non zero elements = 3n-2
// we store data in single array diagonal wise from lower to upper

class TriDiagonal
{

private:
    int *arr;
    int n;

public:
    TriDiagonal(int n)
    {
        this->n = n;
        arr = new int[3 * n - 2];
    }
    ~TriDiagonal()
    {
        delete[] arr;
    }

    void Set(int i, int j, int val)
    {
        if (i - j == 1)
        {
            arr[i - 2] = val;
        }
        else if (j - i == 1)
        {
            arr[2 * n - 1 + i - 1] = val;
        }
        else
        {
            arr[n - 1 + i - 1] = val;
        }
    }

    int Get(int i, int j)
    {
        if (i - j == 1)
        {
            return arr[i - 2];
        }
        else if (j - i == 1)
        {
            return arr[2 * n - 1 + i - 1];
        }
        else
        {
            return arr[n - 1 + i - 1];
        }
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (abs(i - j) > 1)
                    cout << 0 << " ";
                else
                {
                    if (i - j == 1)
                    {
                        cout << arr[i - 2] << " ";
                    }
                    else if (j - i == 1)
                    {
                        cout << arr[2 * n - 1 + i - 1] << " ";
                    }
                    else
                    {
                        cout << arr[n - 1 + i - 1] << " ";
                    }
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    TriDiagonal td(5);
    td.Display();

    return 0;
}