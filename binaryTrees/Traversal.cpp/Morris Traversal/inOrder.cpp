#include <iostream>
#include <vector>
using namespace std;

// Definition of the binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // No left subtree, so just visit and go right
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                // Find the rightmost node in left subtree (inorder predecessor)
                Node* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    // Threading: Make curr the right child of its predecessor
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Already threaded, remove the thread and visit curr
                    prev->right = nullptr;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main() {
    /*
        Constructed Binary Tree:
                  1
                 / \
                2   3
               / \
              4   5

        Inorder traversal (LNR): 4 2 5 1 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> inorderTraversal = sol.inOrder(root);

    cout << "Inorder Traversal (Morris): ";
    for (int val : inorderTraversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
