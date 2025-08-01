#include <iostream>
#include <vector>
using namespace std;

// ---------------------- TreeNode Definition ----------------------
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
        if (left) delete left;
        if (right) delete right;
    }
};

// ---------------------- Inorder Traversal ----------------------
void inorderTraversal(TreeNode<int>* root, vector<int>& inorder) {
    if (root == NULL) return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

// ---------------------- Convert Inorder Vector to Balanced BST ----------------------
TreeNode<int>* inorderToBST(int start, int end, vector<int>& inorder) {
    if (start > end) return NULL;

    int mid = start + (end - start) / 2;
    TreeNode<int>* root = new TreeNode<int>(inorder[mid]);
    root->left = inorderToBST(start, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, end, inorder);
    return root;
}

// ---------------------- Convert BST to Balanced BST ----------------------
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);  // Step 1: Get sorted inorder
    return inorderToBST(0, inorder.size() - 1, inorder);  // Step 2: Convert to balanced BST
}

// ---------------------- Print Inorder (for checking correctness) ----------------------
void printInorder(TreeNode<int>* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// ---------------------- MAIN FUNCTION ----------------------
int main() {
    // ---------------------- Static Unbalanced BST ----------------------
    // Tree:
    //       10
    //      /
    //     6
    //    /
    //   4

    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(4);

    // ---------------------- Balance the BST ----------------------
    TreeNode<int>* balancedRoot = balancedBst(root);

    // ---------------------- Print Inorder of Balanced BST ----------------------
    cout << "Inorder Traversal of Balanced BST: ";
    printInorder(balancedRoot);
    cout << endl;

    // Cleanup (optional)
    delete root;
    delete balancedRoot;

    return 0;
}
