#include <vector>
#include <iostream>
using namespace std;
/* Implementation of stack using array(vectors cpp stl) */

/* Based on principle of last in first out  or first in last out*/
/* whenever we insert and remove from the stack the direction of items gets reversed this principle is used in reversing the direction of
trains in train yards */

class Stack
{
    int size;
    int top;
    int *stkArr;

public:
    Stack()
    {
        cout << "Enter the size of stack: ";
        cin >> size;
        stkArr = new int[size];
        top = -1; // -1 means the stack is empty and stack full condition is size-1
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == size - 1;
    }

    void push(int val)
    {
        if (full())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            stkArr[++top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return stkArr[top--];
        }
    }

    int peek(int pos)
    {
        int x = -1;
        if (top - pos + 1 < 0)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            x = stkArr[top - pos + 1];
        }
        return x;
    }

    int stackTop()
    {
        if (top == -1)
            return -1;
        return stkArr[top];
    }

    void Display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stkArr[i] << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Stack s;
    s.push(1);
    s.push(12);
    s.push(103);
    s.Display();
    cout << endl;
    cout << s.peek(2) << endl;
    return 0;
}
