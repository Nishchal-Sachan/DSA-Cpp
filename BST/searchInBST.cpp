#include <iostream>
using namespace std;

// Definition of Binary Tree Node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// 🔍 Function to search a node in BST
bool searchInBST(BinaryTreeNode<int>* root, int x) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == x) {
        return true;
    }

    if (root->data < x) {
        return searchInBST(root->right, x);
    } else {
        return searchInBST(root->left, x);
    }
}

// 🛠️ Main function with a static BST
int main() {
    /*
        Constructing this BST:
        
                8
              /   \
             3     10
            / \      \
           1   6      14
              / \     /
             4   7   13
    */

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(8);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(10);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(6);
    root->left->right->left = new BinaryTreeNode<int>(4);
    root->left->right->right = new BinaryTreeNode<int>(7);
    root->right->right = new BinaryTreeNode<int>(14);
    root->right->right->left = new BinaryTreeNode<int>(13);

    int searchValue = 13;

    // 🔍 Searching the value
    if (searchInBST(root, searchValue)) {
        cout << "✅ Value " << searchValue << " found in BST." << endl;
    } else {
        cout << "❌ Value " << searchValue << " not found in BST." << endl;
    }

    return 0;
}
