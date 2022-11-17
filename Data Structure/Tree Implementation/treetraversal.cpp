#include<iostream>
using namespace std;
struct Node 
{
	int data;
	struct Node *left, *right;
	
	Node(int data )
	{
		this->data=data;
		left = right = NULL;
	}		
};

//preorder

void preOrder(struct Node *node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->data<<" ";
	preOrder(node->left);
	preOrder(node->right);
	
}

int main()
{
	
	struct Node *head=new Node(1);
	head->left= new Node(4);
	head->right= new Node(5);
	head->left->left=new Node(8);
	head->right->left =new Node(11);
	preOrder(head);
	
}
