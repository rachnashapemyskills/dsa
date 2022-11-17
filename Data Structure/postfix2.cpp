#include <iostream>
using namespace std;
char stack[100];
int n=100, top=-1;
void push(char val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int main() {
    //((a+(b*c))-d)
    char a;
    push('a');
    pop();
    push('+');
    push('b');
    pop();
    push('*');    
    push('c');
    pop();
    pop();
    pop();    
    push('-');
    push('d');
    pop();
    pop();
   return 0;
}
