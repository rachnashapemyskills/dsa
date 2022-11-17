#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data ;
	struct node *next;
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


void sortData()
{
	cout<<"\n Head "<<head<<"\n";
	struct node *current = head, *index = NULL;
  
 	int temp;
 
 	if (head == NULL) {
 		return;
 	} 
	 else {
	 		
 			while (current != NULL) 
			{
			 // index points to the node next to current
				 index = current->next;
				 
				 while (index != NULL) 
				 {
				 	cout<<"\n Current -> Data "<<current->data;
				 	cout<<"\n Index - > Data : "<<index->data;
					 if (current->data > index->data) 
					 {
					 	
					 	temp = current->data;
					 	
					 	current->data = index->data;
					 	
						 index->data = temp;
					 }
 					index = index->next;
 				 }
 				 
 				 cout<<"\n*******************************************\n";
 		current = current->next;
 			}
 		}

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

void searchData(int key)
{
	struct node *current = head;
	int counter;
	while(current!=NULL)
	{
		if(current->data == key)
		{	
			counter =0;
		}
				current=current->next;
			counter++;
		
	}
	cout<<"\n "<<key<<" Found at "<<counter;
}
int main()
{
	 
	insertAtBeg(5);
	insertAtBeg(15);
	insertAtBeg(65);
	insertAtBeg(15);
	insertAtBeg(55);
	insertAtBeg(95);
	insertAtBeg(85);
	showData();
	cout<<"\n Sorted Data \n";
	sortData();
		showData();	
	cout<<"\n ------------------- Data Found --------------------\n";
	searchData(55);
	

	return 0;
}
