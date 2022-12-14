#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // 1 2 3 2 1
        int sum = 0;
        int siz = 0;
        Node *itr = head;
        Node *itr2 = head;
        while (itr->next)
        {
            sum += head->data;
            siz++;
        }
        int mid = (siz / 2) + 1;
        for (int i = 0; i <= mid; i++)
        {
            itr2 = itr2->next;
        }
        
    }
};

int main()
{
    string s = "hello world";
    Solution o;
    // cout << o.isPalindrome();
    return 0;
}