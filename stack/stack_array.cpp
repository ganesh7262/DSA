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

    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == size - 1;
    }
};

int main(int argc, char const *argv[])
{
    Stack s;

    return 0;
}
