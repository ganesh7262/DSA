#include <iostream>
using namespace std;
// int res_max, res_min;
int siz = 10;
int *arr = new int[siz];
struct mm
{
    int min;
    int max;
};
void MinMax(int arr[], int siz)
{
    int min, max;
    min = max = arr[0];
    for (int i = 1; i < siz; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    cout << "Min: " << min << '\n'
         << "Max: " << max << endl;
}

mm MinMax_DAC(int l, int h)
{
    mm temp;
    if (h == l + 1)
    {
        if (arr[l] < arr[h])
        {
            temp.min = arr[l];
            temp.max = arr[h];
            return temp;
        }
        else
        {
            temp.min = arr[h];
            temp.max = arr[l];
            return temp;
        }
    }
    else if (l == h)
    {
        temp.min = temp.max = arr[l];
        return temp;
    }
    else
    {
        int mid = l + (h - l) / 2;
        mm fh = MinMax_DAC(l, mid);
        mm sh = MinMax_DAC(mid + 1, h);
        if (fh.min < sh.min)
        {
            temp.min = fh.min;
        }
        else
            temp.min = sh.min;
        if (fh.max > sh.max)
        {
            temp.max = fh.max;
        }
        else
            temp.max = sh.max;
    }
    return temp;
}

int main()
{
    // Min_Max *res = new Min_Max;
    int temp[10] = {2, 4, 3, 1, 6, 5, 8, 7, 9, 10};

    for (int i = 0; i < siz; i++)
        arr[i] = temp[i];
    // MinMax(arr, siz);
    // MinMax_DAC(0, siz - 1);
    mm res = MinMax_DAC(0, siz - 1);
    cout << "Min: " << res.min << endl;
    cout << "Max: " << res.max << endl;

    return 0;
}