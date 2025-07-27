#include <iostream>
#include <vector>
#include <map>
using namespace std;

// -------------------- Tree Node Structure --------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// -------------------- Solution Class --------------------
class Solution {
public:
    // Mapping node values to their index in inorder array for O(1) access
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Recursive function to build tree
    Node* solve(vector<int>& inorder, vector<int>& postorder, int& index,
                int inorderStart, int inorderEnd, int n, map<int, int>& nodeToIndex) {
        if (index < 0 || inorderStart > inorderEnd)
            return NULL;

        // Get the current root from postorder
        int element = postorder[index--];
        Node* root = new Node(element);

        // Find the position of root in inorder array
        int position = nodeToIndex[element];

        // Build right subtree before left (because we're going backwards in postorder)
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }

    // Main function to build tree
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int n = inorder.size();
        int postOrderIndex = n - 1;
        map<int, int> nodeToIndex;

        createMapping(inorder, nodeToIndex, n);

        return solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
    }
};

// -------------------- Utility Functions --------------------
void printInorder(Node* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(Node* root) {
    if (root == NULL) return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// -------------------- Main Function --------------------
int main() {
    // Sample input
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    Solution obj;
    Node* root = obj.buildTree(inorder, postorder);

    // Verifying output
    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Postorder of constructed tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
