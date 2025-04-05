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

// Function to insert a node at the end
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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

// Sort list with 0s, 1s, and 2s
Node* sortList(Node *head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) zeroCount++;
        else if (temp->data == 1) oneCount++;
        else if (temp->data == 2) twoCount++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        } else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        } else if (twoCount > 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    Node* head = NULL;

    // Sample input: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 1);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
