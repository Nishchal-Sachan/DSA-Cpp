#include <iostream>
#include <algorithm>
using namespace std;

// Node Structure for Binary Tree
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
    // Function returns a pair:
    // first  -> max sum including current node
    // second -> max sum excluding current node
    pair<int, int> solve(Node* root) {
        if (root == NULL)
            return make_pair(0, 0);

        // Recur for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // If we include current node, we cannot include its children
        int include = root->data + left.second + right.second;

        // If we exclude current node, we can include or exclude its children
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return make_pair(include, exclude);
    }

    int getMaxSum(Node* root) {
        pair<int, int> result = solve(root);
        return max(result.first, result.second); // Maximum of including or excluding root
    }
};

// Main Function to test the solution
int main() {
    /*
        Static Binary Tree:

               10
              /  \
             1    2
            / \    \
           3   4    5

        Max sum = 10 (root) + 3 + 4 + 5 = 22 (cannot include 1 or 2)
    */

    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    int maxSum = sol.getMaxSum(root);

    cout << "Maximum sum of non-adjacent nodes: " << maxSum << endl;

    return 0;
}
