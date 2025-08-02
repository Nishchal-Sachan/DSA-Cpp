#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Convert Binary Tree to Doubly Linked List
void convertToDLL(Node* root, Node*& head) {
    if (root == nullptr) {
        return;
    }

    // Recursively convert the left subtree
    convertToDLL(root->left, head);

    // Process the current node
    if (head == nullptr) {
        head = root;  // This will be the head of the DLL
    } else {
        Node* tail = head;
        while (tail->right != nullptr) {
            tail = tail->right;  // Find the last node in the DLL
        }
        tail->right = root;  // Link current node to end
        root->left = tail;   // Link back from current node
    }

    // Recursively convert the right subtree
    convertToDLL(root->right, head);
}

// Print Doubly Linked List from head to tail
void printDLL(Node* head) {
    cout << "Doubly Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

// Print DLL in reverse (tail to head)
void printDLLReverse(Node* head) {
    Node* tail = head;
    while (tail && tail->right != nullptr) {
        tail = tail->right;
    }

    cout << "DLL in Reverse: ";
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->left;
    }
    cout << endl;
}

int main() {
    // Static binary tree:
    /*
           10
          /  \
         5    20
        / \   / \
       2   8 15 25
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    Node* head = nullptr;
    convertToDLL(root, head);

    printDLL(head);
    printDLLReverse(head);

    return 0;
}
