
#include<bits/stdc++.h>
using namespace std;
//this is the simple implementation using array
class myqueue{
 public:
  int size , cap , *arr;
  myqueue(int c){
   size = 0;
   cap = c;
   arr = new int [cap];
  }
  bool empty(){
   return (size == 0);
  }
  bool full(){
   return (size == cap);
  }
  void enqueue(int x){
   if(full()) return;
   arr[size] = x;
   size++;
  }
  void dequeue(){
   if(empty()) return ;
   for(int  i = 0 ;i <size - 1 ;i ++){
    arr[i] = arr[i+1];
   }
   size--;
  }
  int getfront(){
   if(empty()) return -1;
   else return 0;
  }
  int getrear(){
   if(empty()) return -1;
   else return (size - 1);
  }
};
int main()
{
myqueue q(6);
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
q.enqueue(6);
q.dequeue();
cout<<q.getfront()<<endl;
cout<<q.getrear()<<endl;
return 0;
}