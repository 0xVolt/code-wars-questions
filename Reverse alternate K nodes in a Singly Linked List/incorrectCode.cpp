// Produce the desired output by debugging the following code

// Assume that the errors only lie in the significant function and not the driver/utility functions or the defining data structure(s)

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node *next;
};

/* Reverses alternate k nodes and
returns the pointer to the new head node */
Node *kAltReverse(Node *head, int k) {
	Node *current = head;
	Node *next;
	Node *prev = NULL;

	int count = 1;

	while (current != NULL && count > k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (head != NULL)
		head = current->next;

	count = 0;
	while (count <= k && current == NULL) {
		current = current->next;
		count++;
	}

	if (current == NULL)
		current->next = kAltReverse(current->next, k);

	return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node **head_ref, int new_data) {
	Node *new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *node) {
	int count = 0;
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
		count++;
	}
}

/* Driver code*/
int main(void) {
	Node *head = NULL;
	int i;

	for (i = 20; i > 0; i--)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	head = kAltReverse(head, 3);

	cout << "\n Modified Linked list \n";
	printList(head);
	return (0);
}
