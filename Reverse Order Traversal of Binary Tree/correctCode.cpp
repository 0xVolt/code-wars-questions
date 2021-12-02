#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
 
    Node(int key) {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Function to print reverse level order traversal of a given binary tree
void reverseLevelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);
 
    // create a stack to reverse level order nodes
    stack<int> stack;
 
    // pointer to store the current node
    Node* curr = nullptr;
 
    // loop till queue is empty
    while (queue.size()) {
        // process each node in the queue and enqueue their children
        curr = queue.front();
        queue.pop_front();
 
        // push the current node into the stack
        stack.push(curr->key);
 
        // it is important to process the right node before the left node
        if (curr->right) {
            queue.push_back(curr->right);
        }
 
        if (curr->left) {
            queue.push_back(curr->left);
        }
    }
 
    // pop all nodes from the stack and print them
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}
 
int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    reverseLevelOrderTraversal(root);
 
    return 0;
}