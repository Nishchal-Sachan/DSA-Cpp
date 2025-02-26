#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        cout << "Node with value " << data << " deleted successfully!" << endl;
    }
};

// Insert at head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Print linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Reverse the linked list
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// Function to delete the entire linked list
void deleteList(Node *&head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original List: ";
    print(head);

    head = reverse(head);
    cout << "Reversed List: ";
    print(head);

    // Clean up memory
    deleteList(head);

    return 0;
}
