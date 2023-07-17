#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 int data;
 node *next;
 node *prev;
 node(int x)
 {
  data = x;
  next = prev = NULL;
 }
};
void print(node* head){
 node* curr = head;
 while(curr!= NULL){
  cout<<curr->data<<" ";
  curr = curr->next;
 }
}
int main()
{
 node *head = new node(10);
 node *temp1 = new node(20);
 node *temp2 = new node(30);
 head->next = temp1;
 temp1->next = temp2;
 temp1->prev = head;
 temp2->prev = temp1;
 print(head);
}