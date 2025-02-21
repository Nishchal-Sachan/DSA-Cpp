#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

};

// insertion
void insert(Node* &tail, int element,int d ){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        tail = curr;

    }
}

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

int main(){
    Node* tail = NULL;

    insert(tail,3,4);
    print(tail);


    insert(tail,4,6);
    print(tail);

    insert(tail,6,8);
    print(tail);


}