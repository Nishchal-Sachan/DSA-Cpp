#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        cout << "Node with value " << data << " deleted successfully!" << endl;
    }
};

// Insert at head (Fixed)
void insertAtHead(Node *&head, int d) {
    Node *temp = new Node(d);
    temp->next = head;
    
    if (head != NULL) {
        head->prev = temp; // ✅ Fix: Only update prev if head is not NULL
    }

    head = temp;
}

// Print linked list
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse the doubly linked list (Corrected)
Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        curr->prev = temp; // ✅ Correctly swap prev pointers
        prev = curr;
        curr = temp;
    }

    return prev; // ✅ New head of the reversed list
}

// Delete the entire linked list
void deleteList(Node*& head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List deleted successfully!" << endl;
}

int main() {
    Node *head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original List: ";
    print(head);

    head = reverse(head); // ✅ Correctly update head

    cout << "Reversed List: ";
    print(head);

    deleteList(head);
    return 0;
}
