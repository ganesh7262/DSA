#include <iostream>
using namespace std;

void sumpair(int arr[], int siz, int tosum)
{
    for (int i = 0; i < siz; i++)
    {
        for (int j = i + 1; j < siz; j++)
        {
            if (arr[j] == tosum - arr[i])
                cout << "Pair with given sum is: " << arr[i] << " and " << arr[j] << endl;
        }
    }
}

void sumparir2(int arr[], int siz, int sum, int max)
{
    int *hash = new int[max];
    for (int i = 0; i < max; i++)
    {
        hash[i] = 0;
    }
    for (int j = 0; j < siz; j++)
    {
        if (hash[sum - arr[j]] > 0)
        {
            cout << "Pair is : " << arr[j] << " and " << sum - arr[j] << endl;
            hash[arr[j]]++;
        }
        else
            hash[arr[j]]++;
    }
}

void SortedSumPair(int arr[], int siz)
{
    int i = 0;
    int j = siz - 1;
    while (i <= j)
    {
        if (arr[i] + arr[j] > 10)
            j--;
        else if (arr[i] + arr[j] < 10)
            i++;
        else
        {
            cout << "Pair is: " << arr[i] << " and " << arr[j] << endl;
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int siz = 10;
    // sumpair(arr, siz, 10);
    int max = -1;
    for (int i = 0; i < siz; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    // sumparir2(arr, siz, 10, max);
    int soted_arr[10] = {1, 2, 3, 4, 6, 9, 10, 12, 13, 15};
    SortedSumPair(soted_arr, siz);
    return 0;
}