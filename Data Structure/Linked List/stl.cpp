#include<iostream>
//#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	// Constructor
	Node(int n)
	{
		this->data = n;
		this->next = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack() { top = NULL; }

	void push(int data)
	{

		Node* temp = new Node(data);

		if (!temp) {
			cout << "\nStack Overflow";
//			break;
		}
		temp->data = data;

		temp->next = top;

		top = temp;
	}

	bool isEmpty()
	{
		return top == NULL;
	}

	// Utility function to return top element in a stack
	int peek()
	{
		// If stack is not empty , return the top element
		if (!isEmpty())
			return top->data;
//		else
//			break;
	}

	// Function to remove
	// a key from given queue q
	void pop()
	{
		Node* temp ;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow" << endl;
//			break;
		}
		else {

			// Assign top to temp
			temp = top;

			// Assign second node to top
			top = top->next;

			// This will automatically destroy
			// the next between first node and second node

			// Release memory of top node
			// i.e delete the node
			delete (temp);
		}
	}

	// Function to print all the
	// elements of the stack
	void display()
	{
		Node* temp ;

		// Check for stack underflow
		if (top == NULL) {
			cout << "\nStack Underflow";
//			break;
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout << temp->data;

				// Assign temp next to temp
				temp = temp->next;
				if (temp != NULL)
					cout << " -> ";
			}
		}
	}
};

// Driven Program
int main()
{
	// Creating a stack
	Stack s;

	// Push the elements of stack
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);

	// Display stack elements
	s.display();

	// Print top element of stack
	cout << "\nTop element is " << s.peek() << endl;

	// Delete top elements of stack
	s.pop();
	s.pop();

	// Display stack elements
	s.display();

	// Print top element of stack
	cout << "\nTop element is " << s.peek() << endl;

	return 0;
}

