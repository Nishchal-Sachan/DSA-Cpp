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

// Inorder traversal to collect actual node pointers
void inorderTraversal(TreeNode<int>* root, vector<TreeNode<int>*>& inorder) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root);
    inorderTraversal(root->right, inorder);
}

// Flatten using actual nodes (relinking)
TreeNode<int>* flatten(TreeNode<int>* root) {
    if (!root)
        return NULL;

    vector<TreeNode<int>*> inorder;
    inorderTraversal(root, inorder);

    for (int i = 0; i < inorder.size() - 1; i++) {
        inorder[i]->left = NULL;
        inorder[i]->right = inorder[i + 1];
    }

    // Last node
    inorder.back()->left = NULL;
    inorder.back()->right = NULL;

    // Return the first node in inorder as new root
    return inorder[0];
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

    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(15);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(7);
    root->right->right = new TreeNode<int>(20);

    // Flatten using actual nodes
    TreeNode<int>* flatRoot = flatten(root);

    // Print the result
    cout << "Flattened (Right Skewed) Tree: ";
    printRightSkewed(flatRoot);

    // Cleanup
    delete flatRoot;

    return 0;
}
