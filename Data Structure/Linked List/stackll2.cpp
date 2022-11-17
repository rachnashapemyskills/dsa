#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;		// to add data to the node
	struct node *next;	// this is used to add address to the next node 
	
};
struct node* head = NULL;

// Insert Data at the End 
void insertAtEnd(int d)
{
	struct node *newNode=new node;
	struct node *temp= head;
	if(head==NULL)
	{
		newNode->data=d;
		newNode->next=NULL;
		
	}
	else
	{
		
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
		temp->next = newNode;
	}
	
		cout<<"\n DAata inserted";
}


void deleteFromEnd(){
	struct node *temp = head;
	cout<<"\n next -> next of temp "<<temp->next->next;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=NULL;
	cout<<"\n Data Deleted from End\n";
}


void showData(){
	cout<<"\n in show data ";
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n "<<ptr->data;
		ptr = ptr->next;
	}
	cout<<"\n Loop Terminated ";
}
int main()
{
	

	insertAtEnd(99);
	insertAtEnd(199);
	insertAtEnd(299);
	insertAtEnd(399);
	
	showData();
	
//	deleteFromEnd();
//	cout<<"\n************************************************\n";
//	showData();
	


	return 0;
}
