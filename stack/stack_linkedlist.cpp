#include <iostream>
using namespace std;

/* Implementation of stack using linked list */

class Node
{
public:
    int data;
    Node *next;
};

class StackLL
{
    Node *top = nullptr;

public:
    void push(int val)
    {
        Node *t = new Node;
        if (!t)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        t->data = val;
        t->next = top;
        top = t;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }

    int pop()
    {
        int x = -1;
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            Node *p = top;
            top = top->next;
            x = p->data;
            delete p;
        }
        return x;
    }

    int peek(int pos)
    {
        int x = -1;
        Node *t = top;
        for (int i = 0; t && i < pos - 1; i++)
        {
            t = t->next;
        }
        if (t)
            x = t->data;
        return x;
    }

    int stackTop()
    {
        if (top)
            return top->data;
        return -1;
    }

    void Display()
    {
        Node *t = top;
        while (t)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    StackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.Display();
    cout << s.isEmpty();

    return 0;
}