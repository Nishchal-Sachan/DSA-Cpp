#include <iostream>
#include <climits>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;     // Value of the node
    Node* left;   // Pointer to left child
    Node* right;  // Pointer to right child

    // Constructor to initialize node
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Helper recursive function to find the sum of the longest root-to-leaf path
    void solve(Node* root, int sum, int& maxSum, int len, int& maxLen) {
        // Base case: if node is NULL, check if current path is longest or has higher sum
        if (root == NULL) {
            if (len > maxLen) {
                // Found a longer path
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                // Same length: choose path with maximum sum
                maxSum = max(maxSum, sum);
            }
            return;
        }

        // Add current node's value to running sum
        sum += root->data;

        // Recur for left and right subtrees, increasing path length
        solve(root->left, sum, maxSum, len + 1, maxLen);
        solve(root->right, sum, maxSum, len + 1, maxLen);
    }

    // Function to initiate the process and return the final result
    int sumOfLongRootToLeafPath(Node* root) {
        int len = 0;       // Current path length
        int maxLen = 0;    // Maximum path length encountered so far
        int sum = 0;       // Current path sum
        int maxSum = INT_MIN;  // Maximum path sum (initialized to smallest integer)

        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
};

// Main function to test the implementation
int main() {
    /*
        Constructing the following static binary tree:

                1
              /   \
             2     3
            / \     \
           4   5     6
                  /
                 7

        Longest paths:
        - 1 → 2 → 4 (length 3, sum 7)
        - 1 → 2 → 5 (length 3, sum 8)
        - 1 → 3 → 6 → 7 (length 4, sum 17) → longest with max sum
    */

    // Static tree creation
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // Create Solution object and call the function
    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);

    // Output the result
    cout << "Sum of the longest root-to-leaf path: " << result << endl;

    return 0;
}
