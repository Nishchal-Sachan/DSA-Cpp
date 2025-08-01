#include <iostream>
#include <climits>
using namespace std;

// 🔷 Tree Node class
class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// 🔍 Utility function to check if a tree is a BST using range checking
bool isBST(BinaryTreeNode* root, int min, int max) {
    if (root == NULL)
        return true;

    // 🔒 Current node must lie within [min, max)
    if (root->data > min && root->data < max) {
        bool leftIsBST = isBST(root->left, min, root->data);      // Left subtree values must be < root->data
        bool rightIsBST = isBST(root->right, root->data, max);    // Right subtree values must be > root->data
        return leftIsBST && rightIsBST;
    } else {
        return false;
    }
}

// 🚀 Wrapper function to call with initial range
bool validateBST(BinaryTreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// 🖨️ Inorder Traversal (for manual verification)
void inorder(BinaryTreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 🛠️ Main function to test BST validation
int main() {
    /*
        🧱 Static Tree:
        
               8
             /   \
            3     10
           / \      \
          1   6      14
             / \     /
            4   7   13

        ✅ This is a valid BST.
    */

    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(10);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(6);
    root->left->right->left = new BinaryTreeNode(4);
    root->left->right->right = new BinaryTreeNode(7);
    root->right->right = new BinaryTreeNode(14);
    root->right->right->left = new BinaryTreeNode(13);

    cout << "🟩 Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // ✅ Validate BST
    if (validateBST(root)) {
        cout << "✅ The binary tree is a VALID BST." << endl;
    } else {
        cout << "❌ The binary tree is NOT a BST." << endl;
    }

    return 0;
}
