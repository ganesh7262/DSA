#include <iostream>
using namespace std;

/*Lower triangular matrix
    in this j is always greater than i(i<j)*/

class LowerMatrix
{
private:
    int *arr;
    int n;

public:
    LowerMatrix(int n)
    {
        this->n = n;
        arr = new int[n * (n + 1) / 2];
    }
    ~LowerMatrix()
    {
        delete[] arr;
    }

    void Set(int i, int j, int val)
    {
        int idx = (i * (i - 1) / 2) + (j - 1);
        arr[idx] = val;
    }

    int Get(int i, int j)
    {
        if (i < j)
            return 0;
        else
        {
            int idx = (i * (i + 1) / 2) + (j - 1);
            return arr[idx];
        }
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i < j)
                    cout << 0 << " ";
                else
                {
                    int idx = (i * (i + 1) / 2) + (j - 1);
                    cout << arr[idx] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    LowerMatrix lm(5);
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i < j)
                continue;
            cout << "Enter value for: " << i << " " << j << ": ";
            int val;
            cin >> val;
            lm.Set(i, j, val);
        }
    }
    lm.Display();

    return 0;
}