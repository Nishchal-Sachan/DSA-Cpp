#include <iostream>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to find the k-th ancestor of the given node
    Node* solve(Node* root, int& k, int node) {
        if (root == NULL)
            return NULL;

        // If current node matches the target node
        if (root->data == node)
            return root;

        // Search in left and right subtrees
        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        // If node is found in left subtree
        if (leftAns != NULL && rightAns == NULL) {
            k--; // Moving one level up
            if (k == 0) {
                // Current node is the k-th ancestor
                k = INT_MAX; // Lock the answer to prevent further changes
                return root;
            }
            return leftAns;
        }

        // If node is found in right subtree
        if (leftAns == NULL && rightAns != NULL) {
            k--; // Moving one level up
            if (k == 0) {
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }

        // If not found in either subtree
        return NULL;
    }

    // Main function to call the helper and extract final result
    int kthAncestor(Node* root, int k, int node) {
        Node* ans = solve(root, k, node);

        // If the node itself was returned or not found
        if (ans == NULL || ans->data == node)
            return -1;
        else
            return ans->data;
    }
};

// Function to build a sample static binary tree
Node* buildTree() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6

        Example:
        - K-th ancestor of 5 when k=1 → 2
        - K-th ancestor of 5 when k=2 → 1
        - K-th ancestor of 5 when k=3 → -1 (root has no ancestor)
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    return root;
}

int main() {
    Node* root = buildTree();
    Solution sol;

    // Test Cases
    cout << "1st ancestor of 5: " << sol.kthAncestor(root, 1, 5) << endl; // Output: 2
    cout << "2nd ancestor of 5: " << sol.kthAncestor(root, 2, 5) << endl; // Output: 1
    cout << "3rd ancestor of 5: " << sol.kthAncestor(root, 3, 5) << endl; // Output: -1
    cout << "1st ancestor of 3: " << sol.kthAncestor(root, 1, 3) << endl; // Output: 1
    cout << "2nd ancestor of 3: " << sol.kthAncestor(root, 2, 3) << endl; // Output: -1

    return 0;
}
