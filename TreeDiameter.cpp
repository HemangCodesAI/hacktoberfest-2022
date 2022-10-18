// Problem Statement : Find the max Diameter of a tree
// Diameter of a Tree : Maximum path between any two nodes of a tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

int diameter(TreeNode *root, int &maxi)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = diameter(root->left, maxi);
    int right = diameter(root->right, maxi);

    maxi = max(maxi, left + right);

    return 1 + max(left, right);
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
    int maxi;
    diameter(root, maxi);
    cout << maxi << endl;
}