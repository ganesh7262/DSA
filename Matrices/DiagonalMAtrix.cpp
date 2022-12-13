#include <iostream>
using namespace std;

// void Set(int *p, int arr_siz, int i, int j, int val)
// {
//     if (i >= arr_siz || j >= arr_siz)
//     {
//         cout << "Invalid Index" << endl;
//         return;
//     }
//     if (i == j)
//     {
//         p[i] = val;
//     }
// }

// void Get(int *arr, int arr_siz, int i, int j)
// {
//     if (i >= arr_siz || j >= arr_siz)
//     {
//         cout << "Invalid index" << endl;
//         return;
//     }
//     if (i != j)
//     {
//         cout << 0 << endl;
//         return;
//     }
//     cout << arr[i] << endl;
// }

// void Display(int *arr, int arr_siz)
// {
//     for (int i = 0; i < arr_siz; i++)
//     {
//         for (int j = 0; j < arr_siz; j++)
//         {
//             if (i == j)
//                 cout << arr[i] << " ";
//             else
//             {
//                 cout << 0 << " ";
//             }
//         }
//         cout << endl;
//     }
// }

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal(int n)
    {
        this->n = n;
        this->A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }

    void Set(int i, int j, int val)
    {
        if (i == j)
            A[i] = val;
    }

    int Get(int i, int j)
    {
        if (i == j)
            return A[i];
        else
            return 0;
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << A[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Diagonal mat(5);
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value of " << i << " " << i << ": ";
        int val;
        cin >> val;
        mat.Set(i, i, val);
    }

    mat.Display();

    return 0;
}