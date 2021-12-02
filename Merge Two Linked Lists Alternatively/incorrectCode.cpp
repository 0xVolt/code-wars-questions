// Produce the desired output by debugging the following code

// Assume that the errors only lie in the significant function and not the driver/utility functions or the defining data structure(s)

#include <bits/stdc++.h>
using namespace std;

// Definition of a node in a singly linked-list
class Node {
	public:
	int data;
	Node *next;
};

// Function to insert a node at the beginning
void push(Node ** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Utility function to print a singly linked list
void printList(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void merge(Node *p, Node *q) {
	Node *p_curr = p, *q_curr = *q;
	Node *p_next, *q_next;

	while (p_curr->next != NULL && q_curr->next == NULL) {
		p_next = p_curr->next;
		q_next = q_curr->next;

		q_curr = p_next->next;
		p_curr = q_curr;

		p_curr = p_next->next;
		q_curr = q_next->next;
	}

	*q = q_curr->next;
}

// Driver code
int main() {
	Node *p = NULL, *q = NULL;
	push(&p, 3);
	push(&p, 2);
	push(&p, 1);
	cout<<"First Linked List:\n";
	printList(p);

	push(&q, 8);
	push(&q, 7);
	push(&q, 6);
	push(&q, 5);
	push(&q, 4);
	cout<<"Second Linked List:\n";
	printList(q);

	merge(p, &q);

	cout<<"Modified First Linked List:\n";
	printList(p);

	cout<<"Modified Second Linked List:\n";
	printList(q);

	return 0;
}
