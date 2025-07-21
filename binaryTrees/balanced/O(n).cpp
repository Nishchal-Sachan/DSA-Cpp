#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition for a binary tree node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Solution class to check if tree is height-balanced
class Solution
{
public:
    pair<bool, int> solve(Node *root)
    {
        if (root == NULL)
        {
            return make_pair(true, 0); // An empty tree is balanced
        }

        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);

        bool leftCheck = left.first;
        bool rightCheck = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        ans.first = leftCheck && rightCheck && diff;

        return ans;
    }

    bool isBalanced(Node *root)
    {
        return solve(root).first;
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
    bool balanced = sol.isBalanced(root);

    if (balanced)
        cout << "The tree is height-balanced." << endl;
    else
        cout << "The tree is NOT height-balanced." << endl;

    return 0;
}
