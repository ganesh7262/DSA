#include <iostream>
using namespace std;
/* Implementation of Queue using linked list */

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void Enqueue(int num)
    {
        Node *n;
        n->data = num;
        n->next = nullptr;
        if (front == nullptr)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }

    int Dequeue()
    {
        int x = -1;
        Node *p;
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return x;
        }
        p = front;
        x = front->data;
        front = front->next;
        delete p;
        return x;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
