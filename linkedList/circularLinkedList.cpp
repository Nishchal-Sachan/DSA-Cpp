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

// insertion
void insert(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Traversing
void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

// Deletion
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev->next;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    insert(tail, 2, 3);
    print(tail);

    insert(tail, 3, 5);
    print(tail);

    insert(tail, 5, 7);
    print(tail);

    insert(tail, 7, 9);
    print(tail);

    insert(tail, 3, 4);
    print(tail);

    insert(tail, 5, 6);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    deleteNode(tail, 7);
    print(tail);

    return 0;
}