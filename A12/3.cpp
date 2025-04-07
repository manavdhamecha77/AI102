/*
Given the inorder and preorder traversals of a binary tree, write a C/C++ program to construct the binary tree.
Inorder: 1, 8, 19, 13, 25, 9, 5, 10, 4, 3
Preorder: 25, 8, 1, 13, 19, 5, 9, 4, 10, 3
*/

#include <iostream>
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findInorderIndex(int inorder[], int inStart, int inEnd, int value) 
{
    for (int i = inStart; i <= inEnd; ++i) 
    {
        if (inorder[i] == value)
            return i;
    }
    return -1; // shouldn't happen if input is valid
}

// Recursive function to build the tree
TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) 
{
    if (inStart > inEnd)
        return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = findInorderIndex(inorder, inStart, inEnd, rootVal);

    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Main build function
TreeNode* buildTree(int preorder[], int inorder[], int size) 
{
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, size - 1, preIndex);
}

// Traversals
void inorderPrint(TreeNode* root) 
{
    if (!root) return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preorderPrint(TreeNode* root) 
{
    if (!root) return;

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(TreeNode* root) 
{
    if (!root) return;

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

int main() 
{
    int inorder[]  = {1, 8, 19, 13, 25, 9, 5, 10, 4, 3};
    int preorder[] = {25, 8, 1, 13, 19, 5, 9, 4, 10, 3};

    int size = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode* root = buildTree(preorder, inorder, size);

    cout << "Inorder Traversal: ";
    inorderPrint(root);

    cout << "\nPreorder Traversal: ";
    preorderPrint(root);

    cout << "\nPostorder Traversal: ";
    postorderPrint(root);
    cout << endl;

    return 0;
}
