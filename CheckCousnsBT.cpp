// Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not. Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
// Do it in O(n).

// Input format :
// Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
// Line 2 : integer value of p 
// Line 3 : Integer value of q

// Output format :
// true or false

// Input :
// 5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
// 2
// 4

// Sample Output :
// true

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int checkIfSibling(BinaryTreeNode<int>* root, int p1, int p2){
	if(!root) return 0;
	if(root->left && root->right){
		if((root->left->data == p1 && root->right->data == p2) ||
			(root->left->data == p2 && root->right->data == p1)) return 1;
	}
	return (checkIfSibling(root->left,p1,p2) || checkIfSibling(root->right,p1,p2));
}

bool isCousin(BinaryTreeNode<int> *root, int p1, int p2){
	int a = -1, b = -1;
	queue<BinaryTreeNode<int>*> q;
	if(!root) return 0;
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		a = -1, b = -1;
		while(size--){
			BinaryTreeNode<int> *temp = q.front();
			q.pop();
			if(temp->data == p1)
				a = 1;
			else if(temp->data == p2)
				b = 1;
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right); 
		}
		if(a == 1 && b == 1 && !checkIfSibling(root,p1,p2))
			return 1;
	}
	return 0;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
