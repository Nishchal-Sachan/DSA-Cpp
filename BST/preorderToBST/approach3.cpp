#include <bits/stdc++.h>
using namespace std;

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

// Helper recursive function to build BST from preorder
BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int& i) {
    if (i >= preorder.size()) return nullptr;

    if (preorder[i] < mini || preorder[i] > maxi) return nullptr;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);

    root->left = solve(preorder, mini, root->data - 1, i);
    root->right = solve(preorder, root->data + 1, maxi, i);

    return root;
}

// Build BST from preorder in O(n) time
BinaryTreeNode<int>* preorderToBST(vector<int>& preorder) {
    int i = 0;
    return solve(preorder, INT_MIN, INT_MAX, i);
}

// Optional: Inorder traversal to test correctness
void inorderTraversal(BinaryTreeNode<int>* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 15, 12, 20};

    BinaryTreeNode<int>* root = preorderToBST(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    delete root;  // Free memory
    return 0;
}
