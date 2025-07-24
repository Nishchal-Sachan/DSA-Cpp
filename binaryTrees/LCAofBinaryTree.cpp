#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to return the lowest common ancestor (LCA) of two given nodes
    Node* lca(Node* root, int n1, int n2) {
        // Base case: if root is null or matches one of the target nodes
        if (root == NULL) return NULL;

        if (root->data == n1 || root->data == n2) {
            return root;
        }

        // Recur for left and right subtrees
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        // If both sides return non-null, current node is the LCA
        if (leftAns != NULL && rightAns != NULL) {
            return root;
        }

        // If only one side is non-null, return that
        return (leftAns != NULL) ? leftAns : rightAns;
    }
};

// Function to build a static binary tree for testing
Node* buildTree() {
    /*
        Constructing the following tree:
        
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

        LCA(4, 5) = 2
        LCA(4, 6) = 1
        LCA(3, 4) = 1
        LCA(2, 4) = 2
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Node* root = buildTree();
    Solution sol;

    // Test Case 1
    Node* lcaNode = sol.lca(root, 4, 5);
    if (lcaNode)
        cout << "LCA of 4 and 5 is: " << lcaNode->data << endl;

    // Test Case 2
    lcaNode = sol.lca(root, 4, 6);
    if (lcaNode)
        cout << "LCA of 4 and 6 is: " << lcaNode->data << endl;

    // Test Case 3
    lcaNode = sol.lca(root, 3, 4);
    if (lcaNode)
        cout << "LCA of 3 and 4 is: " << lcaNode->data << endl;

    // Test Case 4
    lcaNode = sol.lca(root, 2, 4);
    if (lcaNode)
        cout << "LCA of 2 and 4 is: " << lcaNode->data << endl;

    return 0;
}
