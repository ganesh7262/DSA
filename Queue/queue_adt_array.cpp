#include <iostream>
using namespace std;

/* Queue is based on FIFO(First in first out) there are 2 pointers
front pointer -> Only deletion is done
Rear pointer -> Only Insertion is done
 */

class Queue
{
    int siz;
    int front;
    int rear;
    int *Q;

public:
    Queue(int siz)
    {
        this->siz = siz;
        Q = new int[siz];
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return rear == front;
    }

    bool IsFull()
    {
        return rear == siz - 1;
    }

    void Enqueue(int num)
    {
        if (!IsFull())
        {
            rear++;
            Q[rear] = num;
        }
        else
            cout << "Queue is full" << endl;
    }

    void Dequeue()
    {
        if (!IsEmpty())
        {
            front++;
            Q[front] = NULL;
        }
        else
            cout << "Queue is empty" << endl;
    }

    void Display()
    {
        /* This function is only used for debugging */
        for (int i = 0; i < siz; i++)
            cout << Q[i] << endl;
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Queue q(7);
    for (int i = 0; i < 9; i++)
        q.Enqueue(i);
    q.Display();
    for (int i = 2; i < 5; i++)
        q.Dequeue();
    q.Display();
    return 0;
}
