#include<iostream>
using namespace std;
void showData();
struct node
{
	int data;
	struct node *next;
	struct node *prev;	
};
struct node *head = NULL;
static int node_count = 0;
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
}
void deleteFromBeginning()
{
    struct node *newnode;
    if(head == NULL)
    {
        cout<<"Unable to delete. List is empty. Underflow\n";
    }
    else
    {
        newnode = head;
        head = head->next;      
        if (head != NULL)
            head->prev = NULL; 
        delete newnode; 
        cout<<"SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n";
    }
}
void deleteFromEnd()
{
  
      	if(head == NULL)  
    	{  
        printf("\n UNDERFLOW\n");  
    	}  
        else if (head->next == NULL)
        {
        	 head = NULL;
			 delete head;   
           	 cout<<"SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n";
		}
        else   
    	{     
			struct node *newnode = head;   
	        while(newnode->next != NULL)  
	        {  
	            newnode = newnode->next;   
	        }  
	        newnode->prev->next = NULL;   
	        delete (newnode);  
	        cout<<"\nNode Deleted Successfully!!\n";  
    	}
    }      
	      
void deleteFromN(int position)
{
    struct node *current;
    int i;
    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete(current); 
        cout<<"SUCCESSFULLY DELETED NODE FROM POSITION.\n";
    }
    else
    {
        cout<<"Invalid position!\n";
    }
}

void search()  
{  
    struct node *newnode;  
    int item,i=0,flag;  
    newnode = head;   
    if(newnode == NULL)  
    {  
        cout<<"\nEmpty List\n";  
    }  
    else  
    {   
        cout<<"\nEnter item which you want to search?\n";   
        cin>>item;  
        while (newnode!=NULL)  
        {  
            if(newnode->data == item)  
            {  
                cout<<"\nitem found at location "<<i+1;  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            newnode = newnode -> next;  
        }  
        if(flag==1)  
        {  
            cout<<"\nItem not found\n";  
        }  
    }            
}  
void bubbleSort(struct node *newnode)
{
    int swapp, i;
    struct node *ptr1;
    struct node *lptr = NULL;
    if (newnode == NULL)
        return;
    do
    {
        swapp = 0;
        ptr1 = newnode;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swapp = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapp);
    showData();
    
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
	bubbleSort(myNode);
	
}
int main()
{
	cout<<"\n --------------------------\n";
	int data,choice,op;
	char ch='y' , option;
	insertAtBeg(33);
	insertAtBeg(3);
	insertAtBeg(8);
	insertAtBeg(13);
	insertAtBeg(9);
	insertAtBeg(27);
	while(1)
	{
		
		cout<<"\n Press 1: Insert Data \n Press 2: Show Data \n Press 3: Delete the Data \n Press 4: search \n Press 5: sorting the data\n";
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
			case 3:
				cout<<"\n 1.Delete from begining";
				cout<<"\n 2.Delete from middle";
				cout<<"\n 3.Delete from end";
				cout<<"\n Enter your choice : ";
				cin>>op;
				int n;
				switch(op)
				{
					case 1:
					deleteFromBeginning();
					break;
					case 2:
					cout<<"Enter the node position which you want to delete: ";
                	cin>>n;
                	deleteFromN(n);
					break;
					case 3:
					deleteFromEnd();
				}
			break;
			case 4:
				search();
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
