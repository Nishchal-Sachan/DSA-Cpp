#include <iostream>
#include <queue>
#include <map>
using namespace std;

// -------------------------
// Tree Node Structure
// -------------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// -------------------------
// Solution Class
// -------------------------
class Solution {
public:

    // Helper function to create mapping from each node to its parent
    // and also return the pointer to the target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* targetNode = nullptr;
        queue<Node*> q;

        // Root has no parent
        nodeToParent[root] = nullptr;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Check if current node is the target
            if (current->data == target) {
                targetNode = current;
            }

            // If left child exists, map it to its parent and push into queue
            if (current->left) {
                nodeToParent[current->left] = current;
                q.push(current->left);
            }

            // If right child exists, map it to its parent and push into queue
            if (current->right) {
                nodeToParent[current->right] = current;
                q.push(current->right);
            }
        }

        return targetNode;
    }

    // Function to simulate the burning process of the tree
    int burnTree(Node* targetNode, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> visited;  // Keep track of burned nodes
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burnedNewNode = false;

            // Process all nodes at current level (1 time unit)
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                // Spread fire to left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                    burnedNewNode = true;
                }

                // Spread fire to right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                    burnedNewNode = true;
                }

                // Spread fire to parent node
                Node* parent = nodeToParent[current];
                if (parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                    burnedNewNode = true;
                }
            }

            // If fire spread to any new node in this round, increment time
            if (burnedNewNode) {
                time++;
            }
        }

        return time;
    }

    // Main function to return minimum time to burn the binary tree from the target node
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};

// -------------------------
// Driver Code (Static Tree)
// -------------------------
int main() {
    /*
        Constructing the following binary tree:
        
                 1
                / \
               2   3
              / \    \
             4   5    6

        Let's burn from target node 5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int target = 5;

    Solution obj;
    int result = obj.minTime(root, target);

    cout << "⏳ Time to burn the tree from target node " << target << " is: " << result << " units." << endl;

    return 0;
}
