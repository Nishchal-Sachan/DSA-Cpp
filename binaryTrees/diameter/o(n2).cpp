#include <iostream>
#include <algorithm>
using namespace std;

// Binary Tree Node Definition
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Solution Class with Diameter Logic
class Solution
{
public:
    int height(Node *root)
    {
        if (root == NULL)
        {
            return -1; // height in terms of edges
        }

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    int diameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 2;

        return max(op1, max(op2, op3));
    }
};

int main()
{
    /*
        Sample Tree:
               12
              /  \
             8    18
            / \
           5  11
    */

    Node *root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    Solution sol;
    int dia = sol.diameter(root);

    cout << "Diameter of the tree (in edges): " << dia << endl;

    return 0;
}
