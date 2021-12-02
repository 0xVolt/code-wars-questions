#include <bits/stdc++.h>
using namespace std;

// Define node in a linked list
class Node {
public:
    int data;
    Node *next;
};

// Significant function to rotate a LL about an elt 
void rotateElement(Node **head_ref, int k) {
    if (k == 0)
        return;

    Node *current = *head_ref;

    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    Node *kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

/* UTILITY FUNCTIONS */
void push(Node **head_ref, int new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

// Driver function
int main(void) {
    Node *head = NULL;

    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    cout << "Given linked list \n";
    printList(head);
    rotateElement(&head, 4);

    cout << "\nResulting Linked list \n";
    printList(head);

    return (0);
}
