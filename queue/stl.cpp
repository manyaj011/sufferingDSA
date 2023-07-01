#include<bits/stdc++.h>
using namespace std;
int main()
{
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.pop(); //this popped the item from front cse it follows FIFO order
while(q.empty() == false){
 cout<<q.front()<<" "<<q.back()<<endl;
 q.pop();
}
return 0;
}