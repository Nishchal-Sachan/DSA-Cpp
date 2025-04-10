#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    // Function to get the middle of the linked list
    Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Function to reverse the linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    // Function to check whether the list is palindrome
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        Node* middle = getMiddle(head);
        Node* temp = middle->next;
        middle->next = reverse(temp);

        Node* head1 = head;
        Node* head2 = middle->next;

        while (head2 != NULL) {
            if (head1->data != head2->data) {
                // Restore list before returning
                middle->next = reverse(middle->next);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Restore list before returning
        middle->next = reverse(middle->next);
        return true;
    }
};

// Helper function to insert node at end
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example: Palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 1);

    cout << "Linked List: ";
    printList(head);

    Solution obj;
    if (obj.isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    return 0;
}
