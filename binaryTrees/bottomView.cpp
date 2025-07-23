#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Solution class containing the bottomView method
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;

        // Return empty vector if tree is empty
        if (root == NULL) {
            return ans;
        }

        // Map to store the last node at each horizontal distance (HD)
        map<int, int> node;
        // Queue to perform level order traversal with node and its horizontal distance
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // Overwrite the data at hd, since we want the bottom-most node
            node[hd] = frontNode->data;

            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        // Extracting the bottom view nodes in left-to-right order
        for (auto i : node) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

// Utility function to build a sample binary tree
Node* buildSampleTree() {
    /*
           20
          /  \
         8   22
        / \    \
       5  3    25
          / \
         10 14

    Bottom view = 5, 10, 3, 14, 25
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    return root;
}

// Main function
int main() {
    // Build the sample tree
    Node* root = buildSampleTree();

    // Create an object of the Solution class
    Solution sol;

    // Get the bottom view of the tree
    vector<int> result = sol.bottomView(root);

    // Print the result
    cout << "Bottom View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
