#include <iostream>
#include <vector>
#include <map>
using namespace std;

// -------------------- Node Structure --------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// -------------------- Solution Class --------------------
class Solution {
public:
    // Function to map each node to its index in inorder traversal
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Recursive function to build tree
    Node* solve(vector<int>& inorder, vector<int>& preorder, int& index,
                int inorderStart, int inorderEnd, int n, map<int, int>& nodeToIndex) {

        // Base condition
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        // Step 1: Create root node from preorder
        int element = preorder[index++];
        Node* root = new Node(element);

        // Step 2: Find the index of this element in inorder
        int position = nodeToIndex[element];

        // Step 3: Recursively build left and right subtrees
        root->left = solve(inorder, preorder, index, inorderStart, position - 1, n, nodeToIndex);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }

    // Function to build tree using inorder and preorder
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int n = inorder.size();
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;

        // Map node values to their indices in inorder
        createMapping(inorder, nodeToIndex, n);

        // Call recursive function to build the tree
        return solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
    }
};

// -------------------- Utility Function to Print Tree --------------------
// Inorder traversal of the constructed tree (for verification)
void printInorder(Node* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Preorder traversal of the constructed tree (for verification)
void printPreorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// -------------------- Main Function --------------------
int main() {
    // Sample input
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);

    // Output the tree to verify
    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
