#include <iostream>
using namespace std;

// Definition of Node for BST and DLL
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Convert BST to Sorted Doubly Linked List in reverse in-order (Right → Root → Left)
void convertToDLL(Node* root, Node*& head) {
    if (root == NULL) return;

    convertToDLL(root->right, head);   // Convert right subtree first

    root->right = head;                // Connect root to current head
    if (head != NULL) {
        head->left = root;             // Connect back head to root
    }

    head = root;                       // Move head to root

    convertToDLL(root->left, head);    // Convert left subtree
}

// Merge two sorted doubly linked lists
Node* mergesortedLL(Node*& head1, Node*& head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;

    // Pick the smaller head node
    if (head1->data < head2->data) {
        mergedHead = head1;
        mergedHead->right = mergesortedLL(head1->right, head2);
        if (mergedHead->right != NULL)
            mergedHead->right->left = mergedHead;
    } else {
        mergedHead = head2;
        mergedHead->right = mergesortedLL(head1, head2->right);
        if (mergedHead->right != NULL)
            mergedHead->right->left = mergedHead;
    }
    return mergedHead;
}

// Count nodes in a sorted DLL
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->right;
    }
    return count;
}

// Convert sorted DLL to Balanced BST using in-order fashion
Node* sortedLLToBST(Node*& head, int n) {
    if (n <= 0 || head == NULL)
        return NULL;

    // Build left subtree with first half
    Node* left = sortedLLToBST(head, n / 2);

    // Root node from DLL
    Node* root = head;
    root->left = left;

    // Move head to next node
    head = head->right;

    // Build right subtree with remaining nodes
    root->right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

// Merge two BSTs into one balanced BST
Node* mergeTwoBSTs(Node* root1, Node* root2) {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Convert both BSTs to sorted DLLs
    convertToDLL(root1, head1);
    convertToDLL(root2, head2);

    // Merge the two sorted DLLs
    Node* mergedHead = mergesortedLL(head1, head2);

    // Convert merged DLL to Balanced BST
    int totalNodes = countNodes(mergedHead);
    return sortedLLToBST(mergedHead, totalNodes);
}

// Inorder traversal of BST
void inorderPrint(Node* root) {
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    /*
        First BST:
               10
              /  \
             5   20
    */
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);

    /*
        Second BST:
               15
              /  \
            12    30
    */
    Node* root2 = new Node(15);
    root2->left = new Node(12);
    root2->right = new Node(30);

    // Merge both BSTs into one Balanced BST
    Node* mergedRoot = mergeTwoBSTs(root1, root2);

    cout << "Inorder traversal of the merged balanced BST: ";
    inorderPrint(mergedRoot);  // Output should be sorted merged elements
    cout << endl;

    return 0;
}
