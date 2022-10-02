#include<bits/stdc++.h>
using namespace std;

struct StackNode {

	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data)
{
	struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
}

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int isEmpty(struct StackNode* root)
{
	return !root;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main()
{
	struct StackNode* root = NULL;

	return 0;
}