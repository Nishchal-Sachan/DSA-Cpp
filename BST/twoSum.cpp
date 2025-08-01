#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node Definition
template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Inorder Traversal to get sorted array from BST
void inorderTraversal(BinaryTreeNode<int>* root, vector<int>& inorder) {
    if (root == NULL) return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// Two Sum in BST using Two Pointer Technique
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int s = 0, e = inorder.size() - 1;

    while (s < e) {
        int sum = inorder[s] + inorder[e];

        if (sum == target) {
            return true; // Pair found
        } else if (sum > target) {
            e--;
        } else {
            s++;
        }
    }

    return false; // No such pair found
}

// Test the function
int main() {
    // Create a static BST
    /*
               10
              /  \
             5    15
            / \     \
           2   7     20
    */
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    root->left = new BinaryTreeNode<int>(5);
    root->right = new BinaryTreeNode<int>(15);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(7);
    root->right->right = new BinaryTreeNode<int>(20);

    int target = 22;

    if (twoSumInBST(root, target)) {
        cout << "Pair Found with sum " << target << endl;
    } else {
        cout << "No Pair Found with sum " << target << endl;
    }

    delete root; // Cleanup
    return 0;
}
