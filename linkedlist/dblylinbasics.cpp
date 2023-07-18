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
  prev = next = NULL;
 }
};
node *insertatbegin(node *head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
 {
  return temp;
 }

 temp->next = head;
 head->prev = temp;
 return temp;
}

node *insertatend(node *head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
  return temp;
 node *curr = head;
 while (curr->next != NULL)
 {
  curr = curr->next;
 }
 curr->next = temp;
 temp->prev = curr;
 // temp->next = NULL; ye to already decided h na hmne class m constuctor m yhi to kia h
 return head;
}
void print(node *head)
{
 while (head != NULL)
 {
  cout << head->data << " ";
  head = head->next;
 }
}
node *reverse(node *head)
{
 if (head == NULL || head->next == NULL)
  return head;
 node *curr = head;
 node *prev = NULL;
 while (curr != NULL)
 {
  prev = curr; //this mainains the updated head
  node *temp = curr->next;
  curr->next = curr->prev;
  curr->prev = temp;
  curr = curr->prev;
 }
 return prev;
}

node *deletehead(node *head)
{
 if (head == NULL )
  return NULL; // NULL it is fine if we return head instead of null and why to create cond head->next == NULL;----> jhaan jhaan bhi head change ho rha h we need to make a base condition because usme w'll return a diff modified head
 if(head->next == NULL) {
  delete head;
  return NULL;
 } 
 node *curr = head;
 head = head->next;
 head->prev = NULL;
 delete curr;
 return head;
}

node *deletetail(node *head)
{
 if (head == NULL)
  return NULL;
  if(head->next == NULL){
   delete head;
   return NULL;
  }
 node *curr = head;
 while (curr->next != NULL)
 {
  curr = curr->next;
 }
 curr->prev->next == NULL;
 delete curr;
 return head;
}
int main()
{
 node *head = NULL;
 head = insertatbegin(head, 10);
 head = insertatbegin(head, 20);
 head = insertatbegin(head, 30);
 head = insertatend(head, 40);
 head = insertatend(head, 50);
 head = reverse(head);
 print(head);
}