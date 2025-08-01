#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node Definition
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

// Inorder Traversal Function (stores node values in a vector)
void inorderTraversal(TreeNode<int>* root, vector<int>& inorder) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);   // Left subtree
    inorder.push_back(root->data);           // Root
    inorderTraversal(root->right, inorder);  // Right subtree
}

// Flatten Function (creates a new right-skewed tree from inorder)
TreeNode<int>* flatten(TreeNode<int>* root) {
    if (!root)
        return NULL;

    // Get inorder traversal values
    vector<int> inorder;
    inorderTraversal(root, inorder);

    // Create new tree using inorder values
    TreeNode<int>* newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int>* current = newRoot;

    for (int i = 1; i < inorder.size(); i++) {
        TreeNode<int>* newNode = new TreeNode<int>(inorder[i]);
        current->left = NULL;         // Left should always be NULL
        current->right = newNode;     // Right points to next node
        current = newNode;
    }

    // Last node's left and right should be NULL
    current->left = NULL;
    current->right = NULL;

    return newRoot;
}

// Print the flattened tree (right-skewed)
void printRightSkewed(TreeNode<int>* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// Driver Code
int main() {
    /*
        Constructed Binary Tree:
                10
               /  \
              5    15
             / \     \
            3   7     20

        Expected Inorder: 3 5 7 10 15 20
        Flattened Output: 3 -> 5 -> 7 -> 10 -> 15 -> 20
    */

    // Create static tree
    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(7);
    root->right->right = new TreeNode<int>(20);

    // Flatten the tree and get new root
    TreeNode<int>* flatRoot = flatten(root);

    // Print the flattened tree
    cout << "Flattened (Right Skewed) Tree: ";
    printRightSkewed(flatRoot);

    // Cleanup memory
    delete flatRoot;
    delete root;

    return 0;
}
