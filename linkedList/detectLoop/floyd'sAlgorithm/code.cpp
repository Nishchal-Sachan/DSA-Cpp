

#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
// floyd's algorithm
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Creating nodes
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    // Connecting nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = NULL; // No loop

    // Uncomment the line below to create a loop for testing
    // fourth->next = second; // Creates a loop

    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop in the linked list." << endl;
    }

    return 0;
}
