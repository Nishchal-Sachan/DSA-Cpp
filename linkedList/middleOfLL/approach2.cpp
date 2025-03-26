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
        cout << "Node deleted successfully !" << endl;
    }
};

Node* middleNode(Node* head){
    if(head ==NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        
        fast = fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *mid = middleNode(head);
    cout << "Middle Node: " << mid->data << endl;

    // Freeing allocated memory
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}