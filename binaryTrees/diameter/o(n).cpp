#include <iostream>
#include <algorithm>
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

Node* newNode(int val) {
    return new Node(val);
}

// Solution class
class Solution {
public:
    pair<int, int> solve(Node* root) {
        if (root == NULL) {
            return make_pair(0, 0); // {diameter, height}
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));  // diameter
        ans.second = max(left.second, right.second) + 1;  // height

        return ans;
    }

    int diameter(Node* root) {
        return solve(root).first;
    }
};

int main() {
    /*
        Constructed Binary Tree:
               12
              /  \
             8    18
            / \
           5  11
    */

    Node* root = newNode(12);
    root->left = newNode(8);
    root->right = newNode(18);
    root->left->left = newNode(5);
    root->left->right = newNode(11);

    Solution sol;
    cout << "Diameter of the tree (in nodes): " << sol.diameter(root) << endl;

    return 0;
}
