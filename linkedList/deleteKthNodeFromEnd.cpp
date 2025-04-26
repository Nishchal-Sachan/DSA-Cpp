#include <iostream>
using namespace std;

// Definition of a Node in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
private:
    int getLength(Node* head){
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

public:
    int getKthFromLast(Node *head, int k) {
        int len = getLength(head);
        if(k > len){
            return -1;
        }
        int n = len - k + 1;
        Node* temp = head;
        for(int i = 1; i < n; i++){
            temp = temp->next;
        }
        return temp->data;
    }
};

// Helper function to add a new node at the end
void append(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

// Helper function to print the list (optional, for debug)
void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    Solution sol;
    int k = 2;
    int result = sol.getKthFromLast(head, k);

    if (result != -1) {
        cout << "The " << k << "th node from the end is: " << result << endl;
    } else {
        cout << "The linked list is shorter than " << k << " nodes." << endl;
    }

    return 0;
}
