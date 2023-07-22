// delete node with only pointer given to it

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 node *next;
 int data;
 node(int x)
 {
  next = NULL;
  data = x;
 }
};

node *insertnode(node *head, int x)
{
 node *temp = new node(x);

 if (head == NULL)
 {
  return temp;
 }

 node *curr = head;
 while (curr->next != NULL)
 {
  curr = curr->next;
 }
 curr->next = temp;
 return head;
}

node *pairswap(node *head)
{
 if (head == NULL || head->next == NULL)
  return head;
 node * curr = head;
 while(curr!=NULL && curr->next!=NULL){
  int d = curr->data;
  curr->next->data = curr->data;
  curr->data = d;
  curr = curr->next->next;
 }
 return head;
}
//this is a naive method because in this small data can be copied but if we have so many data and data types in node then this method is not efficient 
//copying chunks of data one by one is foolishness
//so the eff way is to swap the nodes;

//the eff way

node* pairwiseswap(node* head){
 if(head == NULL && head->next == NULL) return head;
 
}
void print(node *head)
{
 if (head == NULL)
  cout << "no item" << endl;
 else
 {
  node *curr = head;
  while (curr != NULL)
  {
   cout << curr->data << " ";
   curr = curr->next;
  }
 }
}
int main()
{
 node *head = NULL;
 head = insertnode(head, 10);
 head = insertnode(head, 20);
 head = insertnode(head, 30);
 head = insertnode(head, 40);
 head = insertnode(head, 50);
 head = insertnode(head, 60);

 print(head);
}