#include<iostream>
using namespace std;
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
   
void addNode(int data) {  
    struct node *newNode = new node;
    newNode->data = data;  
      
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
}  
   
//sortList() will sort the given list in ascending order  
void sortList() {  
    struct node *current = NULL, *index = NULL;  
    int temp;  
   
    if(head == NULL) {  
        return;  
    }  
    else {  
        for(current = head; current->next != NULL; current = current->next) 
		{  
            for(index = current->next; index != NULL; index = index->next) {  
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
            }  
        }  
    }  
}  
   
//display() will print out the nodes of the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        cout<<"List is empty\n";  
        return;  
    }  
    while(current != NULL) {  
        cout<<current->data<<" ";  
        current = current->next;  
    }  
   cout<<"\n";  
}  
   
int main()  
{  
    //Add nodes to the list  
    addNode(7);  
    addNode(1);  
    addNode(4);  
    addNode(5);  
    addNode(2);  
      
    //Displaying original list  
   cout<<("Original list: \n");  
    display();  
      
    //Sorting list  
    sortList();  
      
    //Displaying sorted list  
    cout<<"Sorted list: \n";  
    display();  
   
    return 0;  
}  
