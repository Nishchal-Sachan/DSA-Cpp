#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
private:
    // Count total number of nodes in the tree
    int countNodes(Node* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Check if tree is Complete Binary Tree (CBT)
    bool isCBT(Node* root, int index, int totalNodes) {
        if (root == NULL) {
            return true; // Empty node is valid
        }
        if (index >= totalNodes) {
            return false; // Index out of range → Not CBT
        }

        bool left = isCBT(root->left, 2 * index + 1, totalNodes);
        bool right = isCBT(root->right, 2 * index + 2, totalNodes);
        return left && right;
    }

    // Check Max Heap property
    bool isMaxOrder(Node* root) {
        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return true;
        }

        // Node with only left child
        if (root->right == NULL) {
            return root->data > root->left->data;
        }

        // Node with both children
        return (root->data > root->left->data &&
                root->data > root->right->data &&
                isMaxOrder(root->left) &&
                isMaxOrder(root->right));
    }

public:
    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        return isCBT(tree, 0, totalNodes) && isMaxOrder(tree);
    }
};

// --------------------- MAIN FUNCTION ---------------------
int main() {
    /*
            10
           /  \
          9    8
         / \  /
        7  6 5
    */
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    Solution sol;
    if (sol.isHeap(root)) {
        cout << "The given binary tree is a Max Heap.\n";
    } else {
        cout << "The given binary tree is NOT a Max Heap.\n";
    }

    return 0;
}
