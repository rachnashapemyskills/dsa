#include <iostream>  
#include<queue>  
using namespace std;  
int main()  
{  
 priority_queue<int> p;  // variable declaration.  
 p.push(10); // inserting 10 in a queue, top=10  
 p.push(30); // inserting 30 in a queue, top=30  
 p.push(20); // inserting 20 in a queue, top=20  
 p.push(5);
 p.push(2);
 p.push(90);
 p.push(90);
 cout<<"Number of elements available in 'p' :"<<p.size()<<endl;  
 while(!p.empty())  
 {  
     cout << p.top() << std::endl;   
     p.pop();  
 }  
 return 0;  
}  
