#include <iostream>
using namespace std;

void Duplicate(int arr[], int siz)
{
    int count = 0;
    for (int i = 0; i < siz - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
        else if (count > 0)
        {
            cout << "Duplpicate element is : " << arr[i - 1] << "     "
                 << "No of time of repeat is: " << count << endl;
            // cout << "No of time of repeat is: " << count << endl;
            count = 0;
        }
    }
}

void Duplicates2(int arr[], int siz, int last_elem)
{
    int *temp = new int[last_elem];
    for (int itr = 0; itr < last_elem; itr++)
        temp[itr] = 0;
    for (int i = 0; i < siz - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            temp[arr[i]]++;
    }
    for (int itr2 = 0; itr2 < last_elem; itr2++)
    {
        if (temp[itr2] > 0)
        {
            cout << "Missing element is: " << itr2 << "   "
                 << "No of duplicates is: " << temp[itr2] << endl;
        }
    }
    delete[] temp;
}

void DuplicateInUnsorted(int arr[], int siz)
{
    for (int i = 0; i < siz; i++)
    {
        int c = 0;
        for (int j = i + 1; j < siz; j++)
        {
            if (arr[i] != -1 && arr[j] == arr[i])
            {
                arr[j] = -1;
                c++;
            }
        }
        if (c > 0)
        {
            cout << "Duplicate element is: " << arr[i] << "   "
                 << "Count of Duplicate is: " << c << endl;
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 3, 4, 6, 6, 6, 7, 8};
    int arr2[10] = {1, 3, 1, 4, 5, 7, 4, 8, 4, 12};
    int siz = 10;
    // Duplicate(arr, siz);
    // Duplicates2(arr, siz, arr[siz - 1]);
    DuplicateInUnsorted(arr2, siz);

    return 0;
}