//Using inbuilt stack library to create stack
#include <iostream>
#include <stack>
using namespace std;

int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

    return 0;
}

string convert(string infix)
{
    int i = 0;
    string postfix = "";
    //String [ '\0' ] 
    // using inbuilt stack< > from C++ stack library
    stack <int>s;

    while(infix[i]!='\0')
    {
    	cout<<"\n infix ["<<i<<"] = "<<infix[i]<<"\n";
    	cout<<"\n************************* ****************************\n";
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix = postfix + infix[i];
            cout<<"\n Post fix : "<<postfix<<"\n";
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
//            cout<<"\n Top of Stack = "<<s.top()<<"\n ";
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                cout<<"\n Post fix() : " <<postfix<<"\n";
               	s.pop();
               
            }
           
            s.pop();
            i++;
        }
        else            
        {
        	cout<<"\n priority(infix[i]) : "<<priority(infix[i]);
        	cout<<"\n priority(s.top()) : "<<priority(s.top());
            while (!s.empty() && priority(infix[i]) <= priority(s.top())){
                postfix += s.top();
                cout<<"\n After adding signs "<<postfix<<"\n";
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}



// Prefix

string convertPrefix(string infix)
{
    int i = 0;
    
    string prefix = "";
    string op;
    //String [ '\0' ] 
    // using inbuilt stack< > from C++ stack library
    stack <int>s;

    while(infix[i]!='\0')
    {
    	cout<<"\n infix ["<<i<<"] = "<<infix[i]<<"\n";
    	cout<<"\n************************* ****************************\n";
        // if operand add to the postfix expression
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            prefix =  infix[i]+prefix ;
            cout<<"\n Post fix : "<<prefix<<"\n";
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
//            cout<<"\n Top of Stack = "<<s.top()<<"\n ";
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.top()!='('){
                op=s.top();
                prefix=op+prefix;
                cout<<"\n PRe fix() : " <<prefix<<"\n";
               	s.pop();
               
            }
           
            s.pop();
            i++;
        }
        else            
        {
        	cout<<"\n priority(infix[i]) : "<<priority(infix[i]);
        	cout<<"\n priority(s.top()) : "<<priority(s.top());
            while (!s.empty() && priority(infix[i]) <= priority(s.top())){
                op = s.top();
                prefix= op+prefix;
                cout<<"\n After adding signs "<<prefix<<"\n";
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    cout << "prefix is : " << prefix; //it will print postfix conversion  
    return prefix;
}



int main()
{
    string infix = "((a+(b*c))-d)"; 
    cout<<"\n The infix Value : "<<infix<<"\n";
    string postfix;
    postfix = convertPrefix(infix);
    return 0;
}
