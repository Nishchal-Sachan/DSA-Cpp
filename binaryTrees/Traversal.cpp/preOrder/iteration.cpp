#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TreeNode class definition
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Iterative preorder traversal function
vector<int> preOrder(TreeNode<int>* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode<int>*> st;  // Stack to simulate recursion
    st.push(root);

    while (!st.empty()) {
        TreeNode<int>* temp = st.top();
        st.pop();

        // Visit the root
        ans.push_back(temp->data);

        // Push right child first so that left is processed first
        if (temp->right) {
            st.push(temp->right);
        }
        if (temp->left) {
            st.push(temp->left);
        }
    }

    return ans;
}

// Helper function to build a sample binary tree
TreeNode<int>* buildSampleTree() {
    /*
           1
         /   \
        2     3
       / \   / 
      4   5 6
    */

    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);

    return root;
}

int main() {
    // Build the sample tree
    TreeNode<int>* root = buildSampleTree();

    // Perform preorder traversal
    vector<int> traversal = preOrder(root);

    // Output the result
    cout << "Preorder Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
