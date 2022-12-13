#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    /*
     class for linked list
     in linked list indexing starts from 1 and not zero like array
      */
public:
    int linkedListSize = 0;
    Node *llHead = NULL;
    Node *llTail = NULL;

    void Create_and_append(int arr[], int arr_siz)
    {
        /* For inseting elements in linked list
            takes array and array size as input */
        if (llHead == NULL)
        {
            llHead = new Node;
            llHead->data = arr[0];
            linkedListSize++;

            Node *temp = llHead;
            int idx = 1;
            while (idx < arr_siz)
            {
                Node *newNode = new Node;
                temp->next = newNode;
                temp = temp->next;
                temp->data = arr[idx++];
                linkedListSize++;
            }
            llTail = temp;
            llTail->next = NULL;
        }
        else
        {
            int idx = 0;
            while (idx < arr_siz)
            {
                linkedListSize++;
                Node *newNode = new Node;
                llTail->next = newNode;
                llTail = llTail->next;
                llTail->data = arr[idx++];
            }
            llTail->next = NULL;
        }
    }

    void Display()
    {
        /* Displays the linked list */
        Node *temp = llHead;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int Sum()
    {
        int sum = 0;
        Node *temp = llHead;
        while (temp)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int Max()
    {
        int max = INT_MIN;
        Node *temp = llHead;
        while (temp)
        {
            if (temp->data > max)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }

    Node *Search(int target)
    {
        Node *t = llHead;
        while (t)
        {
            if (t->data == target)
            {
                cout << "Element found" << endl;
                return t;
            }
            t = t->next;
        }
        cout << "Element not found" << endl;
        return nullptr;
    }

    Node *Search2(int target)
    {
        /*
            this is improved version of search
            int linked list we can only peform linear search, hence improved version of search is to bring the target node infront
            so when we serach for it again we will get it on first node
        */

        // int c = 1;
        Node *p, *q;
        q = nullptr;
        p = llHead;
        // cout << c << endl;
        if (p->data == target)
            return p;
        else
            q = p;
        p = p->next;
        while (p)
        {
            // cout << c++ << endl;

            if (p->data == target)
            {
                q->next = p->next;
                p->next = llHead;
                llHead = p;
                return llHead;
            }
            q = p;
            p = p->next;
        }
    }

    void Insert(int index, int val)
    {
        Node *t = new Node;
        if (index < 0)
            return;
        if (index == 0)
        {
            t->data = val;
            t->next = llHead;
            llHead = t;
            linkedListSize++;
        }
        else if (index == linkedListSize)
        {
            t->data = val;
            llTail->next = t;
            llTail = t;
            t->next = NULL;
            linkedListSize++;
        }
        else if (index > 0)
        {
            Node *p = llHead;
            for (int i = 0; i < index - 1 && p; i++)
            {
                p = p->next;
            }
            if (p)
            {
                t->data = val;
                t->next = p->next;
                p->next = t;
                linkedListSize++;
            }
        }
    }

    void NodeDelete(int index)
    {
        if (index == 1)
        {
            Node *t = llHead;
            llHead = llHead->next;
            int x = t->data;
            delete t;
        }
        else if (index > 1)
        {
            Node *itr, *foll;
            itr = llHead;
            for (int i = 0; i < index - 1 && itr; i++)
            {
                foll = itr;
                itr = itr->next;
            }
            foll->next = itr->next;
            int x = itr->data;
            delete itr;
        }
    }
};

/* -----------------------------------------Recursive function-------------------------------------------- */
void RecurseDisp(Node *head)
{
    if (head)
    {
        cout << head->data << endl;
        RecurseDisp(head->next);
    }
}

int RecCount(Node *head)
{
    // static int count = 0;
    if (!head)
    {
        return 0;
    }
    // count++;
    return RecCount(head->next) + 1;
    // return count;

    /*  methood 2:
        if (head != NULL)
        {
            return RecCount(head->next) + 1;
        }
        else
        {
            return 0;
        } */
}

int RecSum(Node *head)
{
    if (!head)
        return 0;
    return head->data + RecSum(head->next);
}

int RecMax(Node *head)
{
    int x = 0;
    if (!head)
        return INT_MIN;

    x = RecMax(head->next);
    if (head->data > x)
        return head->data;
    else
        return x;
}

Node *RecSearch(Node *head, int target)
{
    if (!head)
    {
        cout << "Element not found" << endl;
        return nullptr;
    }
    if (head->data == target)
    {
        cout << "Element found" << endl;
        return head;
    }
    RecSearch(head->next, target);
}

void InsertInSorted(Node *head, int val)
{
    Node *trav = head;
    Node *n = new Node;
    n->data = val;
    /*
    we will need to pass linked list object as parameter for cases where val< head.val as we will need to change the head pointer to new node
         if (val < head->data)
        {
            n->next = head;
            head = n;
            return;
        } */
    while (trav->next && trav->next->data < val)
    {
        trav = trav->next;
    }
    n->next = trav->next;
    trav->next = n;
}

void Issorted(Node *head)
{
    int max = head->data;
    while (head->next)
    {
        head = head->next;
        if (head->data < max)
        {
            cout << "Not sorted" << endl;
            return;
        }
        else
            max = head->data;
    }
    cout << "Sorted" << endl;
}

void RemoveSorted(Node *head)
{
    Node *h, *t;
    h = head->next;
    t = head;
    while (h)
    {
        if (h->data == t->data)
        {
            t->next = h->next;
            delete h;
            h = t->next;
        }
        else
        {
            t = h;
            h = h->next;
        }
    }
}

void ReverseLL(LinkedList *ll)
{
    Node *p, *q, *r;
    p = ll->llHead;
    ll->llTail = ll->llHead;
    // ll->llTail = ll->llHead;
    q = r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    ll->llHead = q;
}

void RecursiveRevLL(LinkedList *ll, Node *prev, Node *cur)
{
    if (!cur->next)
        ll->llHead = cur;
    else
    {
        RecursiveRevLL(ll, cur, cur->next);
    }
    cur->next = prev;
    ll->llTail = cur;
}

void concatLL(LinkedList *l1, LinkedList *l2)
{
    Node *temp = l1->llHead;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = l2->llHead;
    // Node *d = l1->llHead;
    // while (d)
    // {
    //     cout << d->data << endl;
    //     d = d->next;
    // }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr_siz = sizeof(arr) / sizeof(arr[0]);
    LinkedList ll;
    ll.Create_and_append(arr, arr_siz);
    // ll.Create_and_append(arr, arr_siz);
    // ll.Display();
    // int arr2[] = {6, 7, 8, 9, 10};
    // ll.Create_and_append(arr2, arr_siz);
    cout << endl;
    // ll.Display();
    // cout << "Recursive Display" << endl;
    // RecurseDisp(ll.llHead);
    // cout << "Linked List size is: " << ll.linkedListSize << endl;
    // cout << "Linked List size(Using Recursion) is: " << RecCount(ll.llHead) << endl;
    // cout << "Sum is: " << ll.Sum() << endl;
    // cout << "Sum is: " << RecSum(ll.llHead) << endl;
    // cout << "Max of Linked List is: " << ll.Max() << endl;
    // cout << "Max of Linked List is: " << RecMax(ll.llHead) << endl;
    // Node *loc = ll.Search(8);
    // cout << loc->data << endl;
    // Node *loc = RecSearch(ll.llHead, 22);
    // if (loc)
    // {
    //     cout << loc->data << endl;
    // }
    // cout << "counter" << endl;
    // Node *loc = ll.Search2(8);
    // cout << "val: " << loc->data << endl;
    // ll.Display();
    // ll.Insert(10, 100);
    // ll.Display();

    // for (int i = 0; i < 10; i++)
    // {
    //     ll.Insert(ll.linkedListSize, i);
    // }
    // ll.Display();
    /* Merging two linked list */
    LinkedList l1, l2;
    l1.Create_and_append(arr, arr_siz);
    cout << "List1" << endl;
    l1.Display();
    cout << "list2" << endl;
    l2.Create_and_append(arr, arr_siz);
    l2.Display();
    cout << "after merging" << endl;

    return 0;
}