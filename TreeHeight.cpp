// Problem Statement : Find the height of a Tree using the root node.
// Height of a Tree is the longest path between the root & the leaf node of a tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << height(root) << endl;
}