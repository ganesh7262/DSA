#include <iostream>
using namespace std;

/*
    In Doubly linked list each node has 2 node pointers, Node *next as in normal linked list
    and Node* prev from which you can go back to previous Node
    so you can travel in both the direction
    The only feature of this data strcture over singly linked list is that we can travel in both
    the direction
*/

class Node
{
public:
    Node *next;
    int data;
    Node *prev;

    Node()
    {
        next = nullptr;
        data = NULL;
        prev = nullptr;
    }
};

class DlinkedList
{
public:
    Node *first;
    Node *last;
    int listSiz = 0;

    DlinkedList(int arr[], int siz)
    {
        if (!first)
        {
            first = new Node;
            first->data = arr[0];
            listSiz++;

            Node *temp = first;
            Node *p = first;
            for (int i = 1; i < siz; i++)
            {
                temp->next = new Node;
                temp = temp->next;
                temp->data = arr[i];
                temp->prev = p;
                p = temp;
                listSiz++;
            }
            last = temp;
            last->next = nullptr;
        }
    }

    void Display()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void RevDisplay()
    {
        Node *t = last;
        while (t)
        {
            cout << t->data << " -> ";
            t = t->prev;
        }
        cout << endl;
    }

    void Insert(int val, int index)
    {
        Node *nNode = new Node;
        nNode->data = val;
        if (index == 0)
        {
            nNode->next = first;
            first->prev = nNode;
            first = nNode;
            listSiz++;
        }
        else
        {
            Node *t = first;
            for (int i = 0; t && i < index - 1; i++)
            {
                t = t->next;
            }
            nNode->next = t->next;
            nNode->prev = t;
            t->next = nNode;
            if (index == listSiz)
            {
                last = nNode;
            }
            listSiz++;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_siz = sizeof(arr) / sizeof(arr[0]);
    DlinkedList dll = {arr, arr_siz};
    dll.Display();
    dll.Insert(69, 5);
    dll.Display();
    dll.RevDisplay();

    return 0;
}
