#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
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

// Function to check palindrome array
bool checkPalindrome(vector<int>arr){
    int s = 0;
    int e = arr.size()-1;

    while(s<=e){
        if (arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}


// Function to check whether the list is palindrome
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    vector<int> arr;;
    Node* temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}

// Helper function to insert node at end
Node *insertEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Helper function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    // Example: Palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    return 0;
}
