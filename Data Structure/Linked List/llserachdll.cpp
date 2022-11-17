#include <iostream>
using namespace std;

//node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
  private:
    Node* head;
  public:
    LinkedList(){
      head = NULL;
    }
 
    //Add new element at the end of the list
    void push_back(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL; 
      if(head == NULL) {
        head = newNode;
        newNode->next = head;
      } else {
        Node* temp = head;
        while(temp->next != head)
          temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
      }    
    }

    //Search an element in the list
    void SearchElement(int searchValue) {
      Node* temp = head;
      int found = 0;
      int i = 0;

      if(temp != NULL) {
        while(true) {
          i++;
          if(temp->data == searchValue) {
            found++;
            break;
          }
          temp = temp->next;
          if(temp == head) {break;}     
        }
        if (found == 1) {
          cout<<searchValue<<" is found at index = "<<i<<".\n";
        } else {
          cout<<searchValue<<" is not found in the list.\n";
        }
      } else {
        cout<<"The list is empty.\n";
      }
    } 

    //display the content of the list
    void PrintList() {
      Node* temp = head;
      if(temp != NULL) {
        cout<<"The list contains: ";
        while(true) {
          cout<<temp->data<<" ";
          temp = temp->next;
          if(temp == head) 
            break;
        }
        cout<<endl;
      } else {
        cout<<"The list is empty.\n";
      }
    }     
};

// test the code 
int main() {
  LinkedList MyList;

  //Add three elements at the end of the list.
  MyList.push_back(10);
  MyList.push_back(20);
  MyList.push_back(30);

  //traverse to display the content of the list.
  MyList.PrintList();
 
  //search for element in the list
  MyList.SearchElement(10);
  MyList.SearchElement(15);
  MyList.SearchElement(20);

  return 0; 
}
