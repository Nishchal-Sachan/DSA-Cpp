#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next = NULL;

    }
};

Node* kReverse(Node* head,int k ){
    //baseCase
    if(head ==NULL){
        return NULL;
    }

    //step1: reverse first k nodes
    Node* next =NULL;
    Node* curr = head;
    Node* prev=NULL;
    int cnt = 0;
    while(curr!=NULL && cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step2: recursion
    if(next!=NULL){
        head->next = kReverse(next,k);
    }

    //step3: return head
    return prev;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    
    cout << "Original List: ";
    printList(head);
    
    int k = 3;
    head = kReverse(head, k);
    
    cout << "Reversed List in k-groups: ";
    printList(head);
    
    return 0;
}