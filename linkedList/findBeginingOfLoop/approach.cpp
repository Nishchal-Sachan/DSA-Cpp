

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
Node *detectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        slow = slow->next;
        if (slow == fast)
        {
            return fast;
        }
    }
    return NULL;
}
Node *getStartNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = detectLoop(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
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

    // fourth->next = second; // Creates a loop

    if (getStartNode(head) != NULL)
    {
        cout << "Starting Node of the loop." << getStartNode(head)->data;
    }
    else
    {
        cout << "No loop in the linked list." << endl;
    }

    return 0;
}
