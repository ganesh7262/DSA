#include <iostream>
using namespace std;

/*
    The linked list with circular connections is called circular linked list
    there is no first node, insted we have a head node which acts as a refrence node
    its applications include music playlist, mobile contacts(in some cases)
*/

class Node
{
public:
    int data;
    Node *next;
};

class CLinkedList
{
public:
    Node *head = NULL;
    int LLSize = 0;

    void CreateAndAppend(int arr[], int siz)
    {
        Node *itr;
        if (!head)
        {
            head = new Node;
            head->data = arr[0];
            itr = head;
            LLSize++;

            for (int i = 1; i < siz; i++)
            {
                // Node *newNode = new Node;
                // itr->next = newNode;
                itr->next = new Node;
                itr = itr->next;
                itr->data = arr[i];
                LLSize++;
            }
        }
        itr->next = head;
    }

    void Display()
    {
        Node *itr = head;
        do
        {
            cout << itr->data << " -> ";
            itr = itr->next;
        } while (itr != head);
        cout << endl;
    }

    void Insert(int data, int index)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else if (index == 0)
        {
            Node *itr = head;
            while (itr->next != head)
                itr = itr->next;
            newNode->next = itr->next;
            itr->next = newNode;
        }
        else
        {
            if (index > LLSize)
                return;
            else
            {
                Node *itr = head;
                for (int i = 0; i < index - 1; i++)
                    itr = itr->next;

                newNode->next = itr->next;
                itr->next = newNode;
            }
        }
    }

    void Delete(int index)
    {
        if (index == 1)
        {
            Node *trav = head;
            do
            {
                trav = trav->next;
            } while (trav->next != head);
            trav->next = head->next;
            delete head;
            head = trav->next;
            return;
        }
        Node *p, *q;
        p = head->next;
        q = head;
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
            q = q->next;
        }
        q->next = p->next;
        delete p;
    }
};

void RecDisp(Node *head, Node *b)
{
    /* Here we use first parameter for termination condition and second for moving through reccursion */
    /* Node * head will remain fixed parametr and Node*b is head.next  */
    if (b == head)
    {
        // cout << head->data << " -> ";
        return;
    }

    else
    {
        RecDisp(head, b->next);
        cout << b->data << " -> ";
    }
    if (b == head->next)
    {
        cout << head->data << " -> ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr_siz = sizeof(arr) / sizeof(arr[0]);
    CLinkedList cl;
    cl.CreateAndAppend(arr, arr_siz);
    cl.Display();
    cout << endl;
    cl.Delete(1);
    cl.Display();
    return 0;
}