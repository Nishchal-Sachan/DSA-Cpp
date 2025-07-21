#include <iostream>
using namespace std;

// Tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    pair<bool, int> isSum(Node* root) {
        if (root == NULL) {
            return {true, 0};
        }

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return {true, root->data};
        }

        // Recursively check left and right subtrees
        pair<bool, int> leftAns = isSum(root->left);
        pair<bool, int> rightAns = isSum(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool sumCheck = (root->data == leftAns.second + rightAns.second);
        if (left && right && sumCheck) {
            return {true, 2 * root->data};  // Return double for parent check
        } else {
            return {false, 0};
        }
    }

    bool isSumTree(Node* root) {
        return isSum(root).first;
    }
};

// Helper function to build a sample Sum Tree
Node* buildSampleSumTree() {
    /*
            26
           /  \
         10    3
        / \     \
       4   6     3
    */
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    return root;
}

// Main function
int main() {
    Node* root = buildSampleSumTree();
    Solution sol;

    if (sol.isSumTree(root)) {
        cout << "The tree is a Sum Tree." << endl;
    } else {
        cout << "The tree is NOT a Sum Tree." << endl;
    }

    return 0;
}
