#include <iostream>
#define SIZE 5 
using namespace std;

class Queue {
   private:
  	int items[SIZE], front, rear;

   public:
   	
	  Queue() 
	  {
	    front = -1;
	    rear = -1;
	  }
	  
  // Check if the queue is full
	  bool isFull() 
	  {
		    if (front == 0 && rear == SIZE - 1) 
			{
		      return true;
		    }
		    if (front == rear + 1) {
		      return true;
		    }
	    return false;
	  }
	  
  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  // Adding an element
  void enQueue(int element) 
  {
    if (isFull()) 
	{
      cout << "Queue is full";
    } 
	else 
	{
	    if (front == -1) 
		{
	    	front = 0;
		}		
	     
		  rear = (rear + 1) % SIZE;		
		  cout<<"\n Value of rear : "<<rear<<"\n";
	      items[rear] = element;
	      cout << endl
	      << "Inserted " << element << endl;
	}
  }
  // Removing an element
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display() {
    // Function to display status of Circular Queue
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << "Front -> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i] <<" \n ";
      cout << items[i];
      cout << endl
         << "Rear -> " << rear;
    }
  }
};

int main() {
  Queue q;

  // Fails because front = -1
  q.deQueue();

  q.enQueue(10);
  q.enQueue(20);
  q.enQueue(30);
  q.enQueue(40);
  q.enQueue(50);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  q.enQueue(60);

  q.display();

  int elem = q.deQueue();

  if (elem != -1)
    cout << endl
       << "Deleted Element is " << elem;

  q.display();

  q.enQueue(7);

  q.display();

  // Fails to enqueue because front == rear + 1
  q.enQueue(8);

  return 0;
}
