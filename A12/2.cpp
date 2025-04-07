/*
Write a C/C++ program that ask the user to enter 10 integer values. Use these values to construct a binary 
tree with 10 nodes. After constructing the tree, perform and display the inorder, preorder, and postorder 
traversals.
*/


#include <iostream>
using namespace std;

// Definition of a node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a node in BST fashion
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Inorder traversal
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    TreeNode* root = nullptr;
    int value;

    cout << "Enter 10 integer values:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
