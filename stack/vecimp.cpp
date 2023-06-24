//vector implementation of stack
#include<bits/stdc++.h>
using namespace std;
class mystack{
 public:
  vector<int>v;
  void push(int x){
   v.push_back(x);
  }
  int pop(){
   int res = v.back();
   v.pop_back();
   return res;
  }
  int gettop(){
   return v.back();
  }
  bool empty(){
   return v.empty();
  }
};
int main()
{
  mystack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  cout << s.gettop() << endl;
  cout << s.pop() << endl;
  cout << s.empty() << endl;
  return 0;
}