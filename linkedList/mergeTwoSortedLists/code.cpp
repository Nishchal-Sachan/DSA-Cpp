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



Node* solve(Node* first, Node* second){
    if(first->next ==NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1!=NULL  && curr2!=NULL){
        if( (curr2->data >=curr1->data)&&(curr2->data <= next1->data)){
            curr1->next =curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;
            next1=next1->next;

            if(next1==NULL){
                curr1->next = curr2;
            }
        }
    }
    return first;
}
Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    if(first ==NULL){
        return second;
    }if(second ==NULL){
        return first;
    }

    if(first->data <=second->data){
        return solve(first,second);
    }else{
        return solve(second,first);
    }
}

int main() {
    Node* first = NULL;
    Node* second = NULL;

    int n, m, data;
    
    cout << "Enter number of elements in first sorted list: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtHead(first, data);
    }
    
    cout << "Enter number of elements in second sorted list: ";
    cin >> m;
    cout << "Enter elements: ";
    for (int i = 0; i < m; i++) {
        cin >> data;
        insertAtHead(second, data);
    }
    
    Node* mergedList = sortTwoLists(first, second);
    cout << "Merged Sorted List: ";
    print(mergedList);
    
    return 0;
}
