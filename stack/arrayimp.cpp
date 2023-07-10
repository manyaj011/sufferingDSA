//this is pure array implementation
#include<bits/stdc++.h>
using namespace std;

class mystack{
 int *arr;
 int top;
 int cap;
 public:
  mystack(int c){
   cap = c;
   arr = new int[c];
   top = -1;//iniially -1 because we don't have any ele in the stack
  }
  void push(int x){
   if(top == cap - 1){
    cout<<"stack overflow"<<endl;
    return;
   }
   top++;
   arr[top] = x;
  }
  
  int pop(){
   if(top == -1){
    cout<<"stack is empty so nothin to pop"<<endl;
    return -1;
   }
   int res = arr[top];
   top --;
   return res;
  }

  int gettop(){
   if(top == -1) {
    cout<<"there is nthing to top out as the array is empty"<<endl;
    return -1;
   }
   return arr[top];
  }
  bool empty(){
   return (top == -1);
  }
};
int main(){
 mystack s(5);
 s.push(1);
 s.push(2);
 s.push(3);
 s.push(4);
 s.push(5);
 s.push(6);
 cout<<s.gettop()<<endl;
 cout<<s.pop()<<endl;
 cout<<s.empty()<<endl;
 return 0;
}