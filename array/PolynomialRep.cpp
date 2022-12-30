#include <iostream>
using namespace std;
#include <math.h>

class Term
{
public:
    int coef;
    int exp;
};

class Poly
{

public:
    int noTerm;
    Term *t;
    Poly(int N_terms)
    {
        this->noTerm = N_terms;
        this->t = new Term[N_terms];
    }
    ~Poly()
    {
        delete[] t;
    }

    void Read()
    {
        for (int i = 0; i < noTerm; i++)
        {
            cout << "Enter the Coef and exp of term " << i << ": ";
            cin >> t[i].coef >> t[i].exp;
        }
    }

    void Display()
    {
        for (int i = 0; i < noTerm; i++)
        {
            cout << "The Coef and exp of term are: " << t[i].coef << " " << t[i].exp << endl;
        }
    }

    int EvalExp(int valX)
    {
        int i = 0;
        int val = 0;
        while (i < noTerm)
        {
            val += (t[i].coef * pow(valX, t[i].exp));
            i++;
        }
        return val;
    }
};

Poly *_Poly_Add(Poly p1, Poly p2)
{
    int i, j, k;
    i = j = k = 0;
    int res_siz = p1.noTerm + p2.noTerm;
    Poly *res = new Poly(res_siz);
    while (i < p1.noTerm && j < p2.noTerm)
    {
        if (p1.t[i].exp > p2.t[j].exp)
        {
            res->t[k++] = p1.t[i++];
        }
        else if (p1.t[i].exp < p2.t[j].exp)
        {
            res->t[k++] = p2.t[j++];
        }
        else
        {
            res->t[k].coef = p1.t[i].coef + p2.t[j].coef;
            res->t[k++].exp = p1.t[i].exp;
            i++;
            j++;
        }
    }
    if (i < p1.noTerm)
    {
        while (i < p1.noTerm)
        {
            res->t[k++] = p1.t[i++];
        }
    }
    else if (j < p2.noTerm)
    {
        while (j < p2.noTerm)
        {
            res->t[k++] = p2.t[j++];
        }
    }
    res->noTerm = k;

    return res;
}

int main()
{

    Poly p1(3), p2(5);
    p1.Read();
    p2.Read();

    Poly *r = _Poly_Add(p1, p2);
    r->Display();
    // p.Display();
    // cout << "Value of Expression is: " << p.EvalExp(1);

    return 0;
}