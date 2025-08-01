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

// Build Balanced BST from sorted inorder traversal
BinaryTreeNode<int>* inorderToBST(int s, int e, vector<int>& inorder) {
    if (s > e) return nullptr;

    int mid = s + (e - s) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(inorder[mid]);

    root->left = inorderToBST(s, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, e, inorder);

    return root;
}

// Convert preorder to BST by sorting and building balanced BST from inorder
BinaryTreeNode<int>* preorderToBST(vector<int>& preorder) {
    sort(preorder.begin(), preorder.end());  // Convert to inorder
    return inorderToBST(0, preorder.size() - 1, preorder);
}

// Inorder traversal for checking correctness
void inorderTraversal(BinaryTreeNode<int>* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Preorder traversal to visualize structure
void preorderTraversal(BinaryTreeNode<int>* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Main function
int main() {
    vector<int> preorder = {10, 5, 1, 7, 15, 12, 20};

    BinaryTreeNode<int>* root = preorderToBST(preorder);

    cout << "Inorder traversal of BST (should be sorted): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal of constructed BST: ";
    preorderTraversal(root);
    cout << endl;

    delete root;  // Cleanup memory
    return 0;
}
