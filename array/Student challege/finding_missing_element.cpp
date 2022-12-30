#include <iostream>
using namespace std;

void MissingElement(int arr[], int arr_siz)
{
    int diff = arr[0];
    for (int i = 0; i < arr_siz; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << "Missing element is: " << diff + i << endl;
                diff++;
            }
        }
    }
}

void MissingElement2(int arr[], int arr_siz, int n)
{
    int *temp = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        temp[i] = 0;

    for (int j = 0; j < arr_siz; j++)
        temp[arr[j]]++;

    for (int a = 1; a < n + 1; a++)
    {
        if (temp[a] == 0)
            cout << "Missing element is: " << a << endl;
    }

    delete[] temp;
}

int main()
{

    int arr[9] = {1, 2, 3, 4, 6, 9, 10, 11, 12};
    int arr_siz = 9;
    int n = 12;
    // MissingElement(arr, arr_siz);
    MissingElement2(arr, arr_siz, n);
    return 0;
}