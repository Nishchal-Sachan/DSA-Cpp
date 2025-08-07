#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>  // for reverse
using namespace std;

// ---------------- TreeNode Class ----------------
class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// ---------------- Postorder Traversal Function ----------------
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();

        // Visit current node
        ans.push_back(temp->data);

        // Push left first so right is processed before left (since we'll reverse)
        if (temp->left) {
            st.push(temp->left);
        }
        if (temp->right) {
            st.push(temp->right);
        }
    }

    // Reverse the result to get postorder: Left -> Right -> Root
    reverse(ans.begin(), ans.end());

    return ans;
}

// ---------------- Build Sample Tree ----------------
// Example Tree:
//         1
//       /   \
//      2     3
//     / \     \
//    4   5     6
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// ---------------- Main Function ----------------
int main() {
    TreeNode* root = buildSampleTree();

    vector<int> result = postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
