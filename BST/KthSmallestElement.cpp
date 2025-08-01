#include <iostream>
using namespace std;

// Definition of Binary Tree Node
class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to find k-th smallest element using Inorder Traversal
int solve(BinaryTreeNode* root, int &i, int k) {
    if (root == NULL) {
        return -1;
    }

    // Traverse left subtree
    int left = solve(root->left, i, k);
    if (left != -1) return left;

    // Visit current node
    i++;
    if (i == k) return root->data;

    // Traverse right subtree
    return solve(root->right, i, k);
}

// Main function to call for k-th smallest element
int kthSmallest(BinaryTreeNode* root, int k) {
    int i = 0;
    return solve(root, i, k);
}

// Main function to test
int main() {
    /*
            5
           / \
          3   7
         / \   \
        2   4   8
    */

    // Creating the static tree
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(4);
    root->right->right = new BinaryTreeNode(8);

    // Choose k
    int k = 3;

    // Call the function
    int result = kthSmallest(root, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    // Free memory (not mandatory in small test cases but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
