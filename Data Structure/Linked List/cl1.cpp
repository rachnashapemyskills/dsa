#include <iostream>
using namespace std;
struct Node {
 int data;
 struct Node* next;
};


struct Node* addToEmpty(struct Node* head, int data) 
{
 if (head != NULL) 
 	{
		return head;
	}
	struct Node* newNode = new Node;
	newNode->data = data;
	head = newNode;
	head->next = head;
	return head;
}

// add node to the front
struct Node* addFront(struct Node* head, int data) {

 if (head == NULL) 
 {
 	return addToEmpty(head, data);
 }
 
	 struct Node* newNode = new Node;
	 newNode->data = data;
	 newNode->next = head->next;
	 head->next = newNode;
	 return head;
}

// add node to the end
struct Node* addEnd(struct Node* head, int data) 
{
 	if (head == NULL) 
	 {
	 return addToEmpty(head, data);	
	 }
	 struct Node* newNode = new Node;
	 newNode->data = data;
	 newNode->next = head->next;
 
 	head->next = newNode;
 
 	head = newNode;
 	return head;
}


// insert node after a specific node
struct Node* addAfter(struct Node* head, int data, int item) 
{
	 if (head == NULL) 
	 {
	 	return NULL;
	 }
	 struct Node *newNode, *temp;
	 temp = head->next;
	 do {
		 
		 if (temp->data == item) 
		 {
 
 			newNode = new Node;
 
 			newNode->data = data;
 
 			newNode->next = temp->next;
 
 			temp->next = newNode;
 	
 			if (temp == head) {
 				head = newNode;
			 }
 		return head;
 }
		temp= temp->next;
 } while (temp != head->next);
cout << "\nThe given node is not present in the list" << endl;
 return head;
}




void traverse(struct Node* head) {
 	struct Node* p;
	 if (head == NULL) {
			 cout << "The list is empty" << endl;
 			return;
 		}
		 p = head->next;
 	do {
 			cout << p->data << " ";
			 p = p->next;
 	} while (p != head->next);
}


// delete a node
void deleteNode(Node** head, int key) 
{

	 if (*head == NULL) {
	 	cout<<"\n LL is Empty ";
	 	return;
	 }
 // if the list contains only a single node
 	if ((*head)->data == key && (*head)->next == *head) 
	 {
 			delete *head;
 			*head = NULL;
 			cout<<"\n It contains only one node ";
 			return;
 	 }
 	
	 Node *temp = *head, *d;
 	// if head is to be deleted
 		if ((*head)->data == key) 
		 {
 			// find the node before the head node
 			
 			while (temp->next != *head)
			 {
			   temp = temp->next;
			 }
 	
	 
 			temp->next = (*head)->next;
 			delete *head;
 			*head = temp->next;
 	}
		 // travel to the node to be deleted
		while (temp->next != *head && temp->next->data != key) 
		{
		 temp = temp->next;
		}
 
 
 		// if node to be deleted was found
 		if (temp->next->data == key) 
		{
 		d = temp->next;
 		temp->next = d->next;
 		delete d;
 		}
}
   void SearchElement(Node* head,int searchValue) {
      Node* temp = head;
      int found = 0;
      int i = -1;

      if(temp != NULL) {
        while(true) {
          
          if(temp->data == searchValue) {
            found++;
            break;
          }
          temp = temp->next;
          if(temp == head) {break;}     
          i++;
        }
        if (found == 1) {
          cout<<searchValue<<" is found at index = "<<i<<".\n";
        } else {
          cout<<"\n"<<searchValue<<" is not found in the list.\n";
        }
      } else {
        cout<<"The list is empty.\n";
      }
    } 


int main()
{
	 struct Node* head = NULL;
 		head = addToEmpty(head, 6);
 		traverse(head);
		head = addFront(head, 2);
		head = addFront(head, 8);
		head = addFront(head, 5);
		cout<<"\n****************************\n";
		traverse(head);
		cout<<"\n********** Inserting at End ***********\n";
		head = addEnd(head, 16);
		head = addEnd(head, 18);

		traverse(head);
		cout<<"\n Insert at specific location\n";
		int loc;
		cout<<"\n Enter the element ";
		cin>>loc;
		head = addAfter(head, 10, loc);
 		traverse(head);
 		
 		cout<<"\n Enter the element to be deleted  ";
		cin>>loc;
		cout<<"\n After Deleting the DAta \n";
 		deleteNode(&head, loc);
 		cout << endl;
 		traverse(head);
 			cout<<"\n Enter the element to find";
		cin>>loc;
 		SearchElement(head,loc);
}

