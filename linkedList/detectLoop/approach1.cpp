

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

bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            // loop is present
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
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
