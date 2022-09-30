#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int stk[10];
int top=-1;
int main()
{
	int ch;
	while(1)
	{
		printf("\n 1 for push");
		printf("\n 2 for pop");
		printf("\n 3 for display");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
	{
		case 1:
				push();
				break;
		case 2:
				pop();
				break;
		case 3:
				display();
				break;
		case 4:
				exit(0);
		default:
				printf("\n Wrong choice");
		}
	}
}
void push()
{
	if(top==9)
	{
		printf("\n Stack overflow");
		return;
	}
	top++;
	printf("\n Enter data to push : ");
	scanf("%d",&stk[top]);
}
void pop()
{
	if(top == -1)
	{
		printf("\n Stack underflow");
		return;
	}
	printf("\n popped data=%d",stk[top]);
	top--;
}
void display()
{
	int i;
	if(top == -1)
	{
		printf("\n Stack underflow");
		return;
	}
	printf("\n Stack elements are:\n");
	for(i = top; i>=0; i--)
		printf("\n %d",stk[i]);
}
