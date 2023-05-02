#include<bits/stdc++.h>
using namespace std;

class myhash
{
 int bucket;
 list<int> *table;//array of linked list created a pointer table of type test;
 myhash(int b)
 {
  bucket=b;
  table=new list<int>[b];// we add b empty list of array
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
  for(auto x: table[i])
  {
   if(x==key) return true;
   return false;
  }
 }
};
int main()
{
 int b=7;
 myhash obj(int b);
 obj.insert(49);
 obj.insert(63);
 obj.insert(64);
 obj.insert(65);
 obj.insert(70);
 obj.search(63);
 obj.remoce(63);
 obj.search(63);
}