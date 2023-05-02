#include<bits/stdc++.h>
using namespace std;
class myhash
{
 public:
 int bucket;
 list<int>*table; //a pointer table pointing to the linked list...list is a class used to implement doubly linked list..how is it pointing to array of linked list??
 myhash(int b)
 {
  bucket=b;
  table=new list<int>[b]; //we add b empty linked list of array
 }
 void insert(int key)
 {
  int i=key%bucket;
  table[i].push_back(key);
 }
 void remove(int key)
 {
  int i=key%bucket;
  table[i].remove(key);
 }
 bool search(int key)
 {
  int i=key%bucket;
  for(auto x:table[i])
  {
   if(x==key) return true;
   return false;
  }
 }
};
int main()
{
 int b=7;
 myhash m(b);
 m.insert(50);
 m.insert(21);
 m.insert(58);
 m.insert(17);
 m.insert(15);
 m.insert(49);
 m.insert(56);
 m.insert(22);
 m.insert(23);
 m.insert(25);
 cout<<m.search(21);
}