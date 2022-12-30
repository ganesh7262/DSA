#include <iostream>
using namespace std;

class Array
{

private:
    void swap(int *num1, int *num2)
    {
        int temp;
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }

public:
    int *A;
    int size;
    int length;

    void Display()
    {
        for (int i = 0; i < size; i++)
            cout << "index: " << i << "->" << A[i] << endl;
    }

    void add(int num)
    {
        if (length >= size) // checking if the input paramter is right and won't cause an error
        {
            cout << "Array out of size" << endl;
            return;
        }
        A[length] = num;
        cout << "Element successfully added to end of array at index: " << length << endl;
        length++;
    }

    void insert(int idx, int num)
    {
        if (idx >= size || idx < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }
        if (idx < length)
        {
            for (int i = length; i > idx; i--)
            {
                A[i] = A[i - 1];
            }
        }
        A[idx] = num;
        length++;
    }

    void Delete(int idx)
    {
        if (idx >= size || idx >= length || idx < 0)
            return;
        // 0 1 2 3 4 5 6 idx=3 length=7
        for (int i = idx; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        cout << "Element at index: " << idx << " removed" << endl;
    }

    int Search(int target)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == target)
            {
                return i;
            }
        }
        // cout << "Element not found in array" << endl;
        return -1;
    }

    int BinarySearch(int target)
    {
        int l = 0;
        int h = length - 1;
        int m;
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (A[m] == target)
                return m;
            else if (A[m] > target)
                h = m - 1;
            else
                l = m + 1;
        }
        cout << "Element not found" << endl;
        return -1;
    }

    int ReccursiveBS(int target, int h, int l)
    {
        if (l > h)
            return -1;
        int m = l + (h - l) / 2;
        if (A[m] == target)
            return m;
        else if (A[m] > target)
            ReccursiveBS(target, h = m - 1, l);
        else
            ReccursiveBS(target, h, m + 1);
    }

    int Get(int index)
    {
        if (index >= size || index < 0)
            return -1;
        return A[index];
    }

    void Set(int index, int value)
    {
        if (index >= size || index < 0)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        A[index] = value;
    }

    int Max()
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }

    int Min()
    {
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }

    int Average()
    {
        float avg = 0;
        for (int i = 0; i < length; i++)
        {
            avg += A[i];
        }
        return avg / length;
    }

    void Reverse()
    {
        int i = 0;
        int j = length - 1;
        int temp;
        while (i <= j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    void LeftShift()
    {
        // 1 2 3 4 5
        int i = 1;
        while (i < length)
        {
            A[i - 1] = A[i];
            i++;
        }
        A[length - 1] = 0;
    }

    void LeftRotate()
    {
        int i = 1;
        int first_ele = A[0];
        while (i < length)
        {
            A[i - 1] = A[i];
            i++;
        }
        A[length - 1] = first_ele;
    }

    void InsertInSorted(int num)
    {
        // 1 2 3 4 7 9 num=6
        if (length >= size)
        {
            cout << "No space in Array" << endl;
            return;
        }
        int i = length - 1;
        while (A[i] > num)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = num;
        length++;
    }

    bool isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return false;
        }
        return true;
    }

    void NegPosSort()
    {
        int i = 0;
        int j = length - 1;
        while (i <= j)
        {
            while (A[i] < 0)
                i++;
            while (A[j] >= 0)
                j--;
            if (i < j)
                swap(&A[i], &A[j]);
            ;
        }
    }
};

int *Merge(int arr1[], int len1, int arr2[], int len2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int *merged = new int[len1 + len2];
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }
    for (; i < len1; i++)
        merged[k++] = arr1[i];
    for (; j < len2; j++)
        merged[k++] = arr2[j];

    return merged;
}

int *Union_Sorted_arr(int arr1[], int len1, int arr2[], int len2)
{
    int *union_arr = new int[len1 + len2];
    int i, j, k;
    i = j = k = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
            union_arr[k++] = arr1[i++];
        else if (arr2[j] < arr1[i])
            union_arr[k++] = arr2[j++];
        else
        {
            i++;
        }
    }

    for (; i < len1; i++)
    {
        if (union_arr[k] == arr1[i])
            continue;
        else
            union_arr[k++] = arr1[i];
    }
    for (; j < len2; j++)
    {
        if (union_arr[k] == arr2[j])
            continue;
        else
            union_arr[k++] = arr2[j];
    }

    return union_arr;
}

int *Intersection_Sorted_Arr(int arr1[], int len1, int arr2[], int len2)
{
    int i, j, k;
    i = j = k = 0;
    int *ins = new int[len1 + len2];
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            ins[k++] = arr1[i++];
            j++;
        }
    }

    return ins;
}

int *Difference_Sorted_Arr(int arr1[], int len1, int arr2[], int len2)
{
    int i, j, k;
    i = j = k = 0;
    int *diff = new int[len1 + len2];
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            diff[k++] = arr1[i++];
        }
        else if (arr1[i] == arr2[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return diff;
}

int main()
{

    // Array arr;
    // int n;
    // // ---------------------------Input--------------------||
    // cout << "Enter size of array: ";
    // cin >> arr.size;
    // arr.A = new int[arr.size];
    // arr.length = 0;
    // cout << "Enter the number of numbers: ";
    // cin >> n;
    // cout << "Enter all the numbers: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr.A[i];
    // }
    // arr.length = n;
    // arr.Display();
    // ---------------------------Input--------------------||

    // arr.add(10);
    // arr.Display();
    cout << "\nFunction Output: "
         << endl;
    // arr.insert(9, 100);
    // arr.Display();

    // arr.Delete(0);
    // arr.Display();
    // cout << "Elment found at index: " << arr.ReccursiveBS(7, arr.length, 0) << endl;
    // cout << "Left Rotated  Array is: " << endl;
    // arr.LeftRotate();
    // arr.NegPosSort();
    // arr.Display();
    // delete[] arr.A;
    // ------------------------Merged array------------------------//
    int arr1[5] = {1, 3, 4, 6, 8};
    int len1 = 5;
    int arr2[8] = {0, 3, 5, 6, 7, 8, 9, 10};
    int len2 = 8;
    // int *mer = Merge(arr1, len1, arr2, len2);
    int *ans = Difference_Sorted_Arr(arr1, len1, arr2, len2);
    for (int i = 0; i < len1 + len2; i++)
        cout << ans[i] << " ";

    delete[] ans;

    return 0;
}