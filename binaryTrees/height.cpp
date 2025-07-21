#include <iostream>
#include <algorithm> // for max()

using namespace std;

// Definition of the Node class
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

// Solution class containing height function
class Solution
{
public:
    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }
};

int main()
{
    // Manually creating the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \     
    //    4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int h = sol.height(root);
    cout << "Height of the tree: " << h << endl;

    return 0;
}
