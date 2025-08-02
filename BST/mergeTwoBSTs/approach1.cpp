#include <iostream>
#include <vector>
using namespace std;

// Tree Node definition
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder traversal to store elements in sorted array
void inorder(Node* root, vector<int>& inorderVec) {
    if (root == NULL) return;
    inorder(root->left, inorderVec);
    inorderVec.push_back(root->data);
    inorder(root->right, inorderVec);
}

// Merge two sorted arrays into one
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2, vector<int>& merged) {
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }
}

// Convert sorted array to balanced BST
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// Main function to merge BSTs into a balanced BST
Node* mergeBST(Node* root1, Node* root2) {
    vector<int> inorder1, inorder2, merged;
    inorder(root1, inorder1);
    inorder(root2, inorder2);
    mergeSortedArrays(inorder1, inorder2, merged);
    return sortedArrayToBST(merged, 0, merged.size() - 1);
}

// Helper function to print inorder traversal
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Driver code
int main() {
    // Tree 1
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    // Tree 2
    Node* root2 = new Node(3);
    root2->left = new Node(0);
    root2->right = new Node(5);

    // Merge the BSTs
    Node* mergedRoot = mergeBST(root1, root2);

    // Print the inorder traversal of the merged BST
    cout << "Inorder of Merged Balanced BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
