#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insert(root->right, d);
    }
    else
    {
        root->left = insert(root->left, d);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1)
    {
        root = insert(root, data);
        cout << "Enter data (-1 to stop): ";
        cin >> data;
    }
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inOrder(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{
    Node *root = NULL;
    takeInput(root);

    cout << "Binary Search Tree created successfully." << endl;

    cout << "Level Order Traversal:" << endl;
    levelOrder(root);

    cout << "In-Order Traversal:" << endl;
    inOrder(root);

    return 0;
}