#include <iostream>
#include <vector>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class containing the method to count paths with sum k
class Solution {
public:
    // Helper function to recursively explore all paths from root to leaves
    void solve(Node* root, int k, int& count, vector<int>& path) {
        if (root == NULL)
            return;

        // Add current node's value to the path
        path.push_back(root->data);

        // Recur for left and right subtrees
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        // Check all sub-paths ending at this node (from bottom to top)
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }

        // Backtrack: remove current node from path before returning
        path.pop_back();
    }

    // Main function to be called with root and target sum k
    int sumK(Node* root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

// Main function to test the solution
int main() {
    /*
       Constructing the following static binary tree:

               1
              / \
             3  -1
            / \  / \
           2  1 4  5
              /   \
             1     2

        Paths that sum to 5:
        - 3 -> 2
        - 1 -> 3 -> 1
        - 4 -> 1
        - 1 -> -1 -> 4 -> 1
        - 5
    */

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);

    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);

    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->right->right = new Node(2);

    Solution sol;
    int k = 5;

    int result = sol.sumK(root, k);
    cout << "Number of paths with sum " << k << " = " << result << endl;

    return 0;
}
