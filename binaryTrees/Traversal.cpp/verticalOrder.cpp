#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// ----------------------------
// Tree Node Definition
// ----------------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// ----------------------------
// Solution Class
// ----------------------------
class Solution {
public:
    // Function to return the vertical order traversal of a binary tree
    vector<vector<int>> verticalOrder(Node *root) {
        // Map to hold nodes: hd -> level -> list of node values
        map<int, map<int, vector<int>>> nodes;

        // Queue for level order traversal: stores node with its hd and level
        queue<pair<Node*, pair<int, int>>> q;

        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        // Start BFS from root at hd=0 and level=0
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            // Store node value in the map
            nodes[hd][lvl].push_back(frontNode->data);

            // Traverse left subtree with hd - 1
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            }

            // Traverse right subtree with hd + 1
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
            }
        }

        // Flatten the map into answer vector in vertical order
        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                for (auto k : j.second) {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }

        return ans;
    }
};

// ----------------------------
// Main Function with Static Tree
// ----------------------------
int main() {
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
                 \ 
                  8
    */

    // Create tree manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->left->right = new Node(8);

    // Create Solution object
    Solution sol;

    // Call verticalOrder
    vector<vector<int>> result = sol.verticalOrder(root);

    // Print the result
    cout << "Vertical Order Traversal:" << endl;
    for (auto col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
