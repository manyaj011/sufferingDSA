#include<bits/stdc++.h>
using namespace std;
class mydequeue{
public:
 int front , size, cap, *arr;
 
 mydequeue(int c){
  front = 0;
  size = 0;
  cap = c;
  arr = new int [c];
 }
 void insertFront(int x){
  if(isfull()) return;
  int r = getrear();
  size++;
  if(front == 0){
   for(int i = r; i >=0 ; i--){
    arr[i+1] = arr[i];
   }
   arr[0] = x;
  }
  else{
   front--;
   arr[front] = x;
  }

  //this can also be written as 
  //front = (front + cap - 1)%cap;
  //arr[front] = x;
  // size++;
 }

 void insertrear(int x){
  if(isfull()) return;
  int r = getrear();
  r = (r+1)%cap;
  arr[r] = x;
  size ++;
 }

 void deletefront(){
  for(int i = 0 ; i< size-1 ;i++){
   arr[i] = arr[i+1];
  }
  size--;
 }

 int getfront(){
  if(isempty()) return -1;
  else return front;
 }

 int getrear(){
  if(isempty()) return -1;
  return (front + size - 1);
 }

 int isempty(){
  return (size == 0);
 }

 int isfull(){
  return (size == cap);
 }

 void deleterear(){
  if(isempty()){
   cout<<"nothing to delete"<<endl;
  }
  else{
   size--;
  }
 }

 int sizee(){
  cout<<arr[front]<<endl;
  int r = getrear();
  cout<<arr[r]<<endl;
  return size;
 }
 
};
//TC IS O(1)
int main()
{
mydequeue mdq(5);
mdq.insertFront(10);
mdq.insertFront(20);
mdq.insertrear(30);
mdq.insertrear(40);
mdq.insertFront(50);
mdq.deletefront();
mdq.deleterear();
cout<<mdq.sizee()<<endl;
return 0;
}