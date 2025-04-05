

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
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *start = getStartNode(head);
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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

    fourth->next = second; // Creates a loop

    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop in the linked list." << endl;
    }

    removeLoop(head);

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
