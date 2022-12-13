#include <iostream>
using namespace std;

class UpperTriangular
{
public:
    UpperTriangular(int n)
    {
        this->n = n;
        arr = new int[n * (n + 1) / 2];
    }
    ~UpperTriangular()
    {
        delete[] arr;
    }

    void Set(int i, int j, int val)
    {
        int idx = (j * (j - 1))/2 + (i - 1);
        arr[idx] = val;
    }
    int Get(int i, int j)
    {
        int idx = (j * (j - 1))/2 + (i - 1);
        return arr[idx];
    }

    void Display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    cout << 0 << " ";
                else
                {
                    int idx = j * (j - 1) / 2 + (i - 1);
                    cout << arr[idx] << " ";
                }
            }
            cout << endl;
        }
    }

private:
    int *arr;
    int n;
};

int main()
{
    UpperTriangular ut(5);
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i > j)
                continue;
            cout << "Enter value for: " << i << " " << j << ": ";
            int val;
            cin >> val;
            ut.Set(i, j, val);
        }
    }
    ut.Display();
}