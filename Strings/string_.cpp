#include <iostream>
#include <string>
using namespace std;

char str[] = "Ganesh";

void count_vowels(char inp[])
{
    int i;
    int vcount = 0;
    string vowels = "aeiouAEIOU";
    for (int i = 0; inp[i] != '\0'; i++)
    {
        for (auto c : vowels)
        {
            if (inp[i] == c)
            {
                vcount++;
            }
        }
    }
    cout << "No of Vowels are: " << vcount << endl;
}

void CountWord(char inp[])
{
    int wcount = 0;
    for (int i = 0; inp[i] != '\0'; i++)
    {
        if (inp[i] == ' ' && inp[i - 1] != ' ')
            wcount++;
    }
    cout << "No of Words are: " << wcount << endl;
}

void StringValidation(string funinp)
{
    for (auto c : funinp)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            continue;
        }
        else
        {
            cout << "Invalid Sting" << endl;
            return;
        }
    }
    cout << "valid string" << endl;
}

void ReverseSting(char *str)
{
    char *h;
    char *l;
    char temp;
    l = h = str;
    while (*h != '\0')
        h++;
    h--;

    while (l < h)
    {
        temp = *l;
        *l = *h;
        *h = temp;
        l++;
        h--;
    }
}

char *RevStr(char *str)
{
    char *itr = str;
    int siz = 0;
    int i;
    while (*itr != '\0')
    {
        itr++;
        siz++;
    }
    itr--;
    char *revstr = new char[siz];
    for (i = 0; itr >= str; itr--, i++)
    {
        revstr[i] = *itr;
    }
    revstr[i] = '\0';

    return revstr;
}

void CompareStr(char str1[], char str2[])
{
    int i, j;
    for (i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++)
    {
        if (str1[i] != str2[j])
        {
            cout << "Strings are not the same" << endl;
            return;
        }
    }
    if (str1[i] != '\0' || str2[j] != '\0')
    {
        cout << "Strings are not the same" << endl;
    }
    else
    {
        cout << "Strings are the same" << endl;
    }
}

void CheckPalindrome(char str1[])
{
    int i = 0, j = 0;
    while (str1[j] != '\0')
        j++;
    j--;
    while (i < j)
    {
        if (str1[i] != str1[j])
        {
            cout << "String is not a palindrome" << endl;
            return;
        }
        i++;
        j--;
    }
    cout << "String is a palindrome" << endl;
}

void FindingDuplicates(char str1[])
{
    // 61->122
    // 97->122=27
    // Another approcah will be to make everything lower and then 97->0 idx and 27->122 index
    // and we can find index using some calcuations
    int hash[123] = {};
    for (int i = 0; str1[i] != '\0'; i++)
    {
        hash[str1[i]]++;
    }
    for (int i = 1; i < 123; i++)
    {
        if (hash[i] > 1)
        {
            cout << "Duplicate element is: " << char(i) << endl;
        }
    }
}

void FindingDup2(char str1[])
{
    // using bit methood
    int h = 0, x = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        x = 1;
        x = x << str1[i] - 97;
        if ((x & h))
        {
            cout << "Duplicate element is: " << str1[i] << endl;
        }
        else
        {
            h = (h | x);
        }
    }
}

void Anagram(char str1[], char str2[])
{
    // 1->Only useful if there are no duplicates in the string
    // 2-> if there are duplicates then use hash table instead
    // 3-> we are using pass by value ,
    //    if we use call by refrence then checking the length of stings will require different methood(while methood)

    // Commenting the below code as its causing  a waarning
    // int siz1 = sizeof(str1) / sizeof(str1[0]);
    // int siz2 = sizeof(str2) / sizeof(str2[0]);
    // if (siz1 != siz2)
    // {
    //     cout << "Not Anagram" << endl;
    //     return;
    // }
    int b = 0, x = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        x = 1;
        x = x << str1[i] - 97;
        b = (b | x);
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        x = 1;
        x = x << str2[i] - 97;
        if (!(b & x))
        {
            cout << "Not a anagram" << endl;
            return;
        }
    }
    cout << "Anagram" << endl;
}

void PermutationSting(char str1[], int k)
{
    static int flag[10] = {};
    static char res[10] = {};
    // i=0;k=0
    int i = 0;
    if (str1[k] == '\0')
    {
        cout << res << endl;
        return;
    }
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            res[k] = str1[i];
            PermutationSting(str1, k + 1);
            flag[i] = 0;
        }
    }
}
// Global variables
int main()
{
    // ReverseSting(str);
    // global declairation of str is below the libraries
    char str1[] = "medical";
    char str2[] = "decimal";
    char s[] = "abc";
    PermutationSting(s, 0);

    return 0;
}