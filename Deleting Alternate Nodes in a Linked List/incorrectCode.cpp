// Produce the desired output by debugging the following code

// Assume that the errors only lie in the significant function and not the driver/utility functions or the defining data structure(s)

#include <bits/stdc++.h>
using namespace std;

// Define a node of a linked list
struct Node {
    int val;
    Node* next;

    Node(int value){
        val = value;
        next = NULL;
    }
};

/* Utility functions */
void push_front(Node** head, int new_val){
    Node* new_node = new Node(new_val);
    new_node->next = *head;
    *head = new_node;
}

void printList(Node* head){
    Node* i = head;
    while(i){
        cout<<i->val<<" ";
        i = i->next;
    }
    cout<<"\n";
}

// Significant function to delete alternate nodes from a linked list
void delete_alt_nodes(Node* head){
    
    int position = -1;
    Node *prev = NULL;
    
    Node *curr = head;
    while(curr != NULL){
        if(position->next % 2 == 0){
            // delete curr
            prev->next->next = curr;
            Node temp = curr;
            curr = curr->next;
            delete temp->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// Driver function
int main(){
    Node* head = NULL;
    push_front(&head, 8);
    push_front(&head, 6);
    push_front(&head, 2);
    push_front(&head, 5);
    push_front(&head, 3);
    
    cout<<"Original list:\n";
    printList(head);
    // 3 5 2 6 8

    delete_alt_nodes(head);
    
    cout<<"After deleting alternate nodes:\n";
    printList(head);
    // 3 2 8
}