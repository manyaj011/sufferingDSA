#include<bits/stdc++.h>
using namespace std;
class node{
 public:
 int data;
 node*next = NULL;
 node(int x){
  data = x;
  next = NULL;
 }
};
int main()
{
 node *head = new node(10);
 head->next = new node(20);
 head->next->next = new node(30);
 head->next->next->next = head;
 return 0;
}