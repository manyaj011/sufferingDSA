#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 int data;
 node *next; // because a node stores data as well as address to the next node so a node has data of data type int storing value and a pointer that points to the next node because that node has data type node so the pointer ha data type of node*
 node(int x)
 {
  data = x;
  next = NULL;
 }
};
void print(node *head){
 if(head == NULL) cout<<"NULL";
 else{
  node *temp = head;
  while(temp!=NULL){
   cout<<temp->data<<" ";
   temp = temp->next;
  }
 }
}

void rprint(node *head){
 if(head == NULL) return ;
 cout<<head->data<<" ";
 rprint(head->next);
}
int main()
{
 node *head = new node(10);
 head->next = new node(20);
 head->next->next = new node(30);
 print(head);
 cout<<endl;
 rprint(head);
 return 0;
}