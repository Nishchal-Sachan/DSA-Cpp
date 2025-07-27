#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure of the Node of the binary tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        queue<Node*> q;
        q.push(root);
        bool ltr = true;  // left to right

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);  // Resize temp to size

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                int idx = ltr ? i : size - i - 1;
                temp[idx] = frontNode->data;

                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }

            // Append current level's result to final answer
            for (int val : temp) {
                ans.push_back(val);
            }

            ltr = !ltr;  // Toggle direction
        }

        return ans;
    }
};

// Helper function to insert nodes into the tree for testing
Node* buildSampleTree() {
    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
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

// Main function
int main() {
    Node* root = buildSampleTree();

    Solution sol;
    vector<int> result = sol.zigZagTraversal(root);

    cout << "ZigZag Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
