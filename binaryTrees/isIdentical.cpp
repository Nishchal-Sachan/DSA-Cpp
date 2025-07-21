#include <iostream>
using namespace std;

// Node definition for a binary tree
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

// Solution class with isIdentical logic
class Solution {
public:
    bool isIdentical(Node *r1, Node *r2) {
        if (r1 == NULL && r2 == NULL) {
            return true;
        }
        if (r1 == NULL || r2 == NULL) {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool val = (r1->data == r2->data);

        return (left && right && val);
    }
};

int main() {
    /*
        Tree 1:
              1
             / \
            2   3

        Tree 2:
              1
             / \
            2   3
    */

    // Tree 1
    Node* r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    // Tree 2
    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);

    Solution sol;
    if (sol.isIdentical(r1, r2)) {
        cout << "The two trees are identical." << endl;
    } else {
        cout << "The two trees are NOT identical." << endl;
    }

    return 0;
}
