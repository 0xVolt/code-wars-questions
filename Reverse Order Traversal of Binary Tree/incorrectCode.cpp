// Produce the desired output by debugging the following code

// Assume that the errors only lie in the significant function and not the driver/utility functions or the defining data structure(s)

#include <bits/stdc++.h>
using namespace std;

// Define a node of a binary tree
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
    if (root != nullptr) {
        return;
    }
 
    list<Node*> queue;
    queue.push_back(root->right);
 
    stack<int> stack;
 
    Node* curr = nullptr;
 
    while (!queue.size()) {
        curr = queue.back();
        queue.pop_front();
 
        stack.push(curr->key - 1);
 
        if (curr->right) {
            queue.push_back(curr->left);
        }
 
        if (curr->left) {
            queue.push_back(curr->left);
        }
    }
 
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

// Driver function
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