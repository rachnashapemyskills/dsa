#include<iostream>
using namespace std;
struct node{
	int data;  
    struct node *next;  
    struct node *prev;  
};  
struct node *head;  

void insertAtBeg( int d)
{
	struct node *newnode = new node;
	newnode->data= d;
	
	newnode->next=(head);
	
	newnode->prev = NULL;
	if ((head) != NULL)
	{
		(head)->prev = newnode;	 
	}	 
	 // head points to newNode
	 head = newnode;
	
}

void insertlast(int item)  
{  
    
   struct node *newNode = new node;
   struct node *temp;  
   if(newNode == NULL)  
   {  
       cout<<"\n OVERFLOW";  
          
   }  
   else  
   {  
       
        newNode->data=item;  
       if(head == NULL)  
       {  
           newNode->next = NULL;  
           newNode->prev = NULL;  
           head = newNode;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = newNode;  
          newNode ->prev=temp;  
          newNode->next = NULL;  
       }  
	cout<<"\nNode Inserted\n";  
             
   }  
}  

void showData()
{
	struct node *myNode;
	myNode=head;
	while(myNode!=NULL)
	{
		cout<<myNode->data<<" ";
		myNode=myNode->next;
	}
}
int main()
{
	insertlast(99);
	insertAtBeg(88);
	insertlast(87);
	showData();
	cout<<"\n******************************\n";
	int i;
	for(i=1; i<=10; i++)
	{
		insertlast(i);
	}
	showData();
	return 0;
}
