#include <iostream>
using namespace std;

// Definition of Tree Node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ✅ Solution class with flatten function
class Solution {
public:
    void flatten(Node* root) {
        Node* curr = root;

        while (curr != NULL) {
            if (curr->left) {
                // Find the rightmost node in left subtree
                Node* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Attach the original right subtree to the rightmost node
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = NULL;
            }

            // Move to the next right node
            curr = curr->right;
        }
    }
};

// 🔁 Helper function to print the flattened tree
void printFlattened(Node* root) {
    cout << "Flattened Tree (Right Skewed): ";
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// 🔨 Driver Code
int main() {
    /*
          1
         / \
        2   5
       / \   \
      3   4   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution obj;
    obj.flatten(root);

    printFlattened(root);

    return 0;
}
