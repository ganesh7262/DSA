#include <iostream>
using namespace std;

void Insertion(int arr[], int siz)
{
    for (int i = 0; i < siz - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            for (int j = i + 1; j > 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    for (int itr = 0; itr < siz; itr++)
        cout << arr[itr] << " ";
}

int main()
{
    int arr[5] = {12, 11, 13, 5, 6};
    int siz = 5;
    Insertion(arr, siz);

    return 0;
}