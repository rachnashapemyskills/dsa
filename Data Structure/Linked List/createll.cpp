#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;		// to add data to the node
	struct node *next;	// this is used to add address to the next node 
	
};
struct node* head = NULL;
// Insert Data at begning 
void insertAtBeg(int d)
{	
	struct node *newNode=new node;
	newNode->data=d;
	newNode->next = head;
	head=newNode;	
}

// Insert Data at the End 
void insertAtEnd(int d)
{
	struct node *newNode=new node;
	newNode->data=d;
	newNode->next=NULL;
	
	struct node *temp= head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
		temp->next = newNode;
		cout<<"\n DAata inserted";
}
void deleteFromStart(){
	head=head->next;
	cout<<"\n Data Deleted";
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

void insertMiddle(int d)
{
	struct node *newNode=new node;
	newNode->data=d;
	struct node *temp = head;
	for(int i=2; i<3; i++)
	{
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
	}
	newNode->next=temp->next;
	temp->next=newNode;
		
}

void deleteMiddle()
{
	struct node *temp = head;
	for(int i=2; i< 4; i++) {
		 if(temp->next!=NULL) 
		 {
		 	temp = temp->next;
		 }
		}
		temp->next = temp->next->next;
}

void showData(){
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n "<<ptr->data;
		ptr = ptr->next;
	}
}
int main()
{
	insertAtBeg(5);
	insertAtBeg(15);
	insertAtBeg(25);
	showData();
	cout<<"\n Inserted at End\n";
	insertAtEnd(99);
	insertAtEnd(199);
	insertAtEnd(299);
	insertAtEnd(399);
	
	showData();
	cout<<"\n************************************************\n";
	deleteFromStart();
	cout<<"\n************************************************\n";
	showData();
	deleteFromEnd();
	cout<<"\n************************************************\n";
	showData();
	cout<<"\n******************Insert At Middle ******************************\n";
	insertMiddle(88);
	showData();
	cout<<"\n******************Delete at At Middle ******************************\n";
	deleteMiddle();
	showData();
	


	return 0;
}
