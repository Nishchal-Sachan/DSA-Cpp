#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node Definition
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Insert a value into the BST
BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int d) {
    if (root == nullptr) {
        return new BinaryTreeNode<int>(d);
    }

    if (d > root->data) {
        root->right = insert(root->right, d);
    } else {
        root->left = insert(root->left, d);
    }

    return root;
}

// Convert preorder vector to BST
BinaryTreeNode<int>* preorderToBST(vector<int>& preorder) {
    BinaryTreeNode<int>* root = nullptr;
    for (int i = 0; i < preorder.size(); i++) {
        root = insert(root, preorder[i]);
    }
    return root;
}

// Inorder Traversal to verify BST
void inorderTraversal(BinaryTreeNode<int>* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder Traversal for verification
void preorderTraversal(BinaryTreeNode<int>* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Main Function
int main() {
    vector<int> preorder = {10, 5, 1, 7, 15, 12, 20};

    BinaryTreeNode<int>* root = preorderToBST(preorder);

    cout << "Inorder traversal (should be sorted): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal (should match input): ";
    preorderTraversal(root);
    cout << endl;

    // Clean up memory
    delete root;

    return 0;
}
