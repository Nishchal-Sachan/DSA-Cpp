#include <iostream>
#include <vector>
using namespace std;

// Tree Node
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

class Solution {
  public:
    void leftTraverse(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if (root->left) leftTraverse(root->left, ans);
        else leftTraverse(root->right, ans);
    }

    void leafTraverse(Node* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        leafTraverse(root->left, ans);
        leafTraverse(root->right, ans);
    }

    void rightTraverse(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) return;
        if (root->right) rightTraverse(root->right, ans);
        else rightTraverse(root->left, ans);
        ans.push_back(root->data);  // Add after recursion for bottom-up
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        if (!(root->left == NULL && root->right == NULL))  // skip if root is leaf
            ans.push_back(root->data);

        leftTraverse(root->left, ans);
        leafTraverse(root, ans);  // include both left & right subtrees
        rightTraverse(root->right, ans);

        return ans;
    }
};

// Helper function to build a sample binary tree
Node* buildSampleTree() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
               / \
              7   8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    return root;
}

// Main function
int main() {
    Node* root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
