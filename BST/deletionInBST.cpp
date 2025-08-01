#include <iostream>
using namespace std;

// 🌳 Definition of a BST Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// 🔥 BST Deletion Function
Node* deleteNode(Node* root, int x) {
    if (root == NULL) {
        return root;
    }

    // If the value to be deleted is found
    if (root->data == x) {
        // 🧱 Case 1: Leaf node (no children)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 🌿 Case 2: Only right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 🍃 Case 3: Only left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 🌳 Case 4: Two children
        if (root->left != NULL && root->right != NULL) {
            // Find in-order successor (minimum value in right subtree)
            Node* minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            root->data = minNode->data; // Replace value
            root->right = deleteNode(root->right, minNode->data); // Delete successor
            return root;
        }
    }
    // Recurse in left or right subtree
    else if (x < root->data) {
        root->left = deleteNode(root->left, x);
        return root;
    } else {
        root->right = deleteNode(root->right, x);
        return root;
    }
}

// 🖨️ Inorder Traversal for Printing Tree
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// 🛠️ Main Function to Demonstrate Deletion
int main() {
    /*
        BST Structure:

               8
             /   \
            3     10
           / \      \
          1   6      14
             / \     /
            4   7   13
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << "🟢 Original BST (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    int valToDelete = 3;
    root = deleteNode(root, valToDelete);

    cout << "🧹 BST after deleting " << valToDelete << " (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
