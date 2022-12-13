#include <iostream>
#include <vector>
using namespace std;

// Sparese matrix are matrix where no. of zeroes are more than no. of values
// Positiions of the zeroes might not have a symmetry
// we store sparse matrix as a tabale with three columns(row,col,val) we define it using a structure or class

class Element
{
public:
    int i;
    int j;
    int val;
};

class Sparse
{

public:
    int row;
    int col;
    int no_val;
    Element *e;
    Sparse(int row, int col, int no_val)
    {
        this->row = row;
        this->col = col;
        this->no_val = no_val;
        this->e = new Element[no_val];
    }

    ~Sparse()
    {
        delete[] e;
    }
    void Read()
    {
        cout << "Fill the Sparse Matrix: " << endl;
        for (int i = 0; i < no_val; i++)
        {
            cout << "Enter row,column,val: ";
            cin >> e[i].i >> e[i].j >> e[i].val;
            cout << endl;
        }
    }

    void Display()
    {
        int k = 0;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (e[k].i == i && e[k].j == j)
                {
                    cout << e[k++].val << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
};

// void Display(Sparse *s)
// {
//     for (int i = 0; i < s->no_val; i++)
//     {
//         cout << "Row: " << s->e[i].i << " col: " << s->e[i].j << " val: " << s->e[i].val << endl;
//     }
//     cout << "\n";
// }

Sparse *Add(Sparse *s1, Sparse *s2)
{
    if (s1->row != s2->row || s1->col != s2->col)
    {
        cout << "Matrix of unequal dimensions cannot be added together" << endl;
        return 0;
    }

    Sparse *res = new Sparse(s1->row, s1->col, s1->no_val + s2->no_val);
    // res->e = new Element[res_siz];
    int i, j;
    i = j = 0;
    int idx = 0;
    while (i < s1->no_val && j < s2->no_val)
    {
        if (s1->e[i].i < s2->e[j].i)
        {
            res->e[idx++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i)
        {
            res->e[idx++] = s2->e[j++];
        }
        else if (s1->e[i].j < s2->e[j].j)
        {
            res->e[idx++] = s1->e[i++];
        }
        else if (s1->e[i].j > s2->e[j].j)
        {
            res->e[idx++] = s2->e[j++];
        }
        else
        {
            res->e[idx++] = s1->e[i++];
        }
    }
    if (i < s1->no_val)
    {
        while (i < s1->no_val)
        {
            res->e[idx++] = s1->e[i++];
        }
    }
    else if (j < s2->no_val)
    {
        while (j < s2->no_val)
        {
            res->e[idx++] = s2->e[j++];
        }
    }
    return res;
}

int main()
{
    // Sparse s1, s2;
    Sparse s1(2, 2, 3);
    s1.Read();
    // Create(&s2);
    cout << "\n";
    s1.Display();
    // Display(&s2);
    // Sparse *res = Add(&s1, &s2);
    // Display(res);

    return 0;
}