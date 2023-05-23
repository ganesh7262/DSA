#include <iostream>
#include <queue>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild = nullptr;
    treeNode *rightChild = nullptr;
};

class Tree : private treeNode
{
public:
    treeNode *createTree()
    {
        queue<treeNode *> qtree;
        treeNode *root = new treeNode;
        cout << "Enter the root node value: " << endl;
        int rootData;
        cin >> rootData;
        root->data = rootData;
        qtree.push(root);

        while (!qtree.empty())
        {
            treeNode *temp = qtree.front();
            qtree.pop();
            cout << "Enter the value of left node of tree (-1 if no left node): " << endl;
            int lData;
            cin >> lData;
            if (lData != -1)
            {
                treeNode *new_Node = new treeNode;
                temp->leftChild = new_Node;
                new_Node->data = lData;
                qtree.push(new_Node);
            }
            cout << "Enter the value of Right node of tree (-1 if no Right node): " << endl;
            int rData;
            cin >> rData;
            if (rData != -1)
            {
                treeNode *new_Node = new treeNode;
                temp->rightChild = new_Node;
                new_Node->data = rData;
                qtree.push(new_Node);
            }
        }
        return root;
    }

    void preordertraversal(treeNode *root)
    {
        if (root)
        {
            cout << root->data << endl;
            preordertraversal(root->leftChild);
            preordertraversal(root->rightChild);
        }
    }
};

int main(int argc, char const *argv[])
{
    Tree t;
    treeNode *root = t.createTree();
    t.preordertraversal(root);

    return 0;
}
