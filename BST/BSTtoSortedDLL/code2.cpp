#include <iostream>
using namespace std;

// Definition for Binary Tree Node
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

// Function to convert Binary Tree to Doubly Linked List
void convertToDLL(Node* root, Node*& head) {
    if (root == NULL) return;

    // Convert right subtree first
    convertToDLL(root->right, head);

    // Connect root node
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }

    // Move head to current node
    head = root;

    // Convert left subtree
    convertToDLL(root->left, head);
}

// Function to print Doubly Linked List
void printDLL(Node* head) {
    cout << "Doubly Linked List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    /*
        Constructing the following Binary Tree:
                  10
                 /  \
                6    14
               / \   / \
              4   8 12 16
    */

    Node* root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(14);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(16);

    Node* head = NULL;

    convertToDLL(root, head);

    printDLL(head);

    return 0;
}
