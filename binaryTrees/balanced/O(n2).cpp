#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Solution class using naive approach
class Solution {
public:
    int height(Node* root) {
        if (root == NULL) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(Node* root) {
        if (root == NULL) {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && diff) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    /*
        Sample Tree:
               12
              /  \
             8    18
            / \
           5  11
    */

    Node* root = new Node(12);
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
