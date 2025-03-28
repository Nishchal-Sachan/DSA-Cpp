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
        cout << "Node deleted successfully!" << endl;
    }
};

// Insert at head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Traversing the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr;
        while(temp->next!=NULL){
            if(temp->next->data == curr->data){
                Node* nodeToDelete = temp->next;
                temp->next=temp->next->next;
                delete nodeToDelete;
            }else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
    return head;
}

// Main function
int main()
{
    Node *head = NULL;

    // Creating a linked list with duplicate values
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Original Linked List: ";
    print(head);

    // Removing duplicates
    head = removeDuplicates(head);

    cout << "Linked List after removing duplicates: ";
    print(head);

    return 0;
}
