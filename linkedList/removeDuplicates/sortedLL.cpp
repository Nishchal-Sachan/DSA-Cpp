#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev; // Added for Doubly Linked List

    // Constructor
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }

    // Destructor
    ~Node() {
        cout << "Node with data " << data << " deleted successfully!" << endl;
    }
};

// Insert at head for a Doubly Linked List
void insertAtHead(Node *&head, int d) {
    Node *temp = new Node(d);
    if (head != NULL) {
        head->prev = temp;
    }
    temp->next = head;
    head = temp;
}

// Print the doubly linked list
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Remove duplicates from a sorted doubly linked list
Node *removeDuplicates(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node *temp = curr->next;
            curr->next = temp->next;
            if (temp->next != NULL) { // Update prev pointer only if next node exists
                temp->next->prev = curr;
            }
            delete temp; // Free memory
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Delete the doubly linked list to free memory
void deleteList(Node *&head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = NULL;

    // Creating a sorted doubly linked list with duplicates: 4 <-> 3 <-> 3 <-> 3 <-> 2 <-> 2 <-> 1
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 4);

    cout << "Original Doubly Linked List: ";
    print(head);

    head = removeDuplicates(head);

    cout << "Doubly Linked List after removing duplicates: ";
    print(head);

    // Free memory
    deleteList(head);

    return 0;
}
