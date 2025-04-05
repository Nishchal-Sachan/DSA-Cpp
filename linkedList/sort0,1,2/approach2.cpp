#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert a node at the end using value
void insertValue(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to insert a node at the end of a specific list
void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Sort list with 0s, 1s, and 2s using dummy node approach
Node* sortList(Node *head) {
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0) {
            insertAtTail(zeroTail, curr);
        } else if (curr->data == 1) {
            insertAtTail(oneTail, curr);
        } else {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // Connecting the three lists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // Updated head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Sample input: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    int values[] = {1, 2, 0, 1, 2, 0, 1};
    for (int val : values) {
        insertValue(head, tail, val);
    }

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
