#include<bits/stdc++.h>
using namespace std;
class twostacks{
 int *arr;
 int cap;
 int top1 ,top2;
 public:
  twostacks(int c)
  {
   cap = c;
   top1 = -1;
   top2 = c;
   arr = new int[c];
  }
  bool push1(int x){
   if(top1 < top2 - 1){
    top1 ++ ;
    arr[top1] == x;
    return true;
   }
   return false;
  }
  bool push2(int x){
   if(top1 < top2 -1){
    top2--;
    arr[top2] = x;
    return true;
   }
   return false;
  }
  int pop1(){
   if(top1 >= 0){
    int res = arr[top1];
    top1--;
    return res;
   }
   else return -1;
  }
  int pop2(){
   if(top2 < cap){
    int res = arr[top2];
    top2++;
    return res;
   }
   return -1;
  }
  int size1(){
   return (top1 + 1);
  }
  int size2(){
   return (cap - top2);
  }
};
int main(){
 
}