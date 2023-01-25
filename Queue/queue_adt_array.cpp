#include <iostream>
using namespace std;

/* Queue is based on FIFO(First in first out) there are 2 pointers
front pointer -> Only deletion is done
Rear pointer -> Only Insertion is done
Drawbacks:
1->we cannot reuse the spaces of deleted elements
2->each space in queue can only be used once
3->when f=r=siz-1 the queue is empty as well as full because of the condition we defined
Solution :
Using circular queue
*/

class Queue
{
    int siz;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        /* Non parametric constructor with default queue size of 10 */
        siz = 10;
        front = rear = -1;
        Q = new int[siz];
    }
    Queue(int siz)
    {
        /* Parametric constructor with queue size as parameter */
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

    int Dequeue()
    {
        int x = -1;
        if (!IsEmpty())
        {
            front++;
            x = Q[front];
            Q[front] = NULL;
            return x;
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

class CircularQueue
{
    int siz;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue()
    {
        /* Non parametric constructor with default queue size of 10 */
        siz = 10;
        front = rear = -1;
        Q = new int[siz];
    }
    CircularQueue(int siz)
    {
        /* Parametric constructor with queue size as parameter */
        this->siz = siz;
        Q = new int[siz];
        front = rear = -1;
    }
    bool IsFull()
    {
        return (rear + 1) % siz == front;
    }

    bool Isempty()
    {
        return front == rear;
    }

    void Enqueue(int num)
    {
        if (!IsFull())
        {
            rear = (rear + 1) % siz;
            Q[rear] = num;
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }

    int Dequeue()
    {
        int x = -1;
        if (!Isempty())
        {
            front = (front + 1) % 7;
            x = Q[front];
            Q[front] = NULL;
            return x;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
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
    CircularQueue q(6);
    for (int i = 1; i <= 6; i++)
        q.Enqueue(i);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Display();
    q.Enqueue(90);
    q.Display();
    q.Enqueue(60);
    q.Enqueue(80);
    q.Display();

    return 0;
}
