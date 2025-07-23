#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// ----------------------------
// Definition of the Tree Node
// ----------------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// ----------------------------
// Solution Class with Top View
// ----------------------------
class Solution {
  public:
    // Function to return a list of nodes visible from the top view of the binary tree
    vector<int> topView(Node *root) {
        vector<int> ans;

        // Edge case: empty tree
        if (root == NULL) {
            return ans;
        }

        // Map to store first node at each horizontal distance (hd)
        map<int, int> nodeAtHD;

        // Queue to perform level order traversal (BFS)
        // Each entry holds a node and its corresponding horizontal distance
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0)); // root is at horizontal distance 0

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // If this horizontal distance is not yet recorded, record it
            if (nodeAtHD.find(hd) == nodeAtHD.end()) {
                nodeAtHD[hd] = frontNode->data;
            }

            // Enqueue left child with horizontal distance hd - 1
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            // Enqueue right child with horizontal distance hd + 1
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        // Collect the top view nodes in left-to-right order (sorted by hd)
        for (auto it : nodeAtHD) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// ----------------------------
// Main Function to Test the Code
// ----------------------------
int main() {
    /*
         Sample Tree:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
                   \
                    8

        Expected Top View: 4 2 1 3 7
    */

    // Construct the tree statically
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->left->right = new Node(8);

    // Create an instance of Solution and call topView
    Solution sol;
    vector<int> result = sol.topView(root);

    // Output the result
    cout << "Top View of the Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
