#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;	
};

struct node *head = NULL;
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

void insertAtEnd(int d)
{
	struct node *newNode=new node;
	newNode->data = d;
	if(head==NULL)
	{
		newNode->prev=NULL;
		newNode->next=NULL;
		head=newNode;		
	}

	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp = temp->next;		
	}
		temp->next=newNode;
		newNode->prev=temp;
		 newNode->next = NULL;
	
	
}


// insert a node after a specific node
void insertAfter(int data) 
{
 	if (head == NULL) 
	 {
 		cout << "previous node cannot be NULL";
     }
     
 		struct node* newNode = new node;
 		
 		newNode->data = data;
 
 		newNode->next = head->next;
 		 		
 		head->next = newNode;
 		
 		newNode->prev = head;
 	
//	 if (newNode->next != NULL)
//	{
//		newNode->next->prev = newNode;
//	}
 		
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
	int data,choice;
	char ch='y' , option;
	while(1)
	{
		
		cout<<"\n Press 1: Insert Data \n Press 2: Show Data \n Press 3: Delete the Data \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n Enter the data ";
				cin>>data;
				cout<<"\n Press a: Insert At Begning \n Press b: Insert At Last \n Press c: Insert After\n";
				cin>>option;
				switch(option)
				{
					case 'a':
					insertAtBeg(data);
					break;
				case 'b':
					insertAtEnd(data);
					break;
				case 'c':
					insertAfter(data);
					break;
				}
			break;
			case 2:
				showData();
				break;
			
				
				
		}
		cout<<"\n Do you want to continue ??";
		cin>>ch;
		if(ch=='n'|| ch=='N')
		{
			break;
		}
	
	}
	
	
	return 0;	
}
