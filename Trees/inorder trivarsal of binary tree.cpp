#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

// Function to print inorder traversal
void printInorder(struct Node* node)
{
    if (node == nullptr)
        return;

    // First recur on left subtree
    printInorder(node->left);

    // Now deal with the node
    cout << node->data << " ";

    // Then recur on right subtree
    printInorder(node->right);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printInorder(root);

    return 0;
}