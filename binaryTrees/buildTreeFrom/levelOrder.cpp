#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// -------------------- Tree Node Structure --------------------
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// -------------------- Function to Build Tree from Level Order --------------------
Node* buildTree(vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1)
        return NULL;

    // Create the root node
    Node* root = new Node(levelOrder[0]);

    // Queue to manage level-wise node insertion
    queue<Node*> q;
    q.push(root);

    int i = 1; // Index for traversing the levelOrder array

    while (!q.empty() && i < levelOrder.size()) {
        Node* current = q.front();
        q.pop();

        // Process left child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->left = new Node(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        // Process right child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new Node(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// -------------------- Utility Functions --------------------
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr) {
            cout << curr->data << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

// -------------------- Main Function --------------------
int main() {
    // -1 indicates NULL in level-order
    vector<int> levelOrder = {1, 2, 3, -1, 4, 5, -1};

    Node* root = buildTree(levelOrder);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    cout << "Level Order (with -1 as NULLs): ";
    printLevelOrder(root);
    cout << endl;

    return 0;
}
