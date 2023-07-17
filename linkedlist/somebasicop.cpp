#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 int data;
 node *next;
 node(int x)
 {
  data = x;
  next = NULL;
 }
};
// create a fun that insert node at the beginning and return the new head
node *insertatbegin(node *head, int x)
{
 node *temp = new node(x);
 temp->next = head;
 return temp;
}
void rprint(node *head)
{
 if (head == NULL)
  return;
 cout << head->data << " ";
 rprint(head->next);
}

node *insertatend(node *head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
 {
  temp->next = head; // no need to do this beacuse temp will be our new head then
  return temp;
 }
 else
 {
  node *curr = head;
  while (curr->next != NULL)
  {
   curr = curr->next;
  }
  curr->next = temp;
  return head;
 }
 // tc o(n)
}

node *insertatmiddle(node *head, int x, int pos)
{
 node *temp = new node(x);
 if (pos == 1)
 {
  temp->next = head;
  return temp;
 }
 node *curr = head;
 for (int i = 1; i <= pos - 2; i++)
 {
  curr = curr->next;
 }
 if (curr == NULL)
  return head;
 temp->next = curr->next;
 curr->next = temp;
 return head;
}

node *deletehead(node *head)
{
 if (head == NULL)
  return NULL;
 else
 {
  node *temp = head->next;
  delete head; // we need to deallocate the memory also
  return temp;
 }
}
node *deletetail(node *head)
{
 if (head == NULL)
  return NULL;
 node *curr = head;
 while (curr->next->next != NULL)
 { // this is because we need atleast 2 nodes in linked list if wehave only curr->next != NULL then we only have to we can del curr but uske prev ko null bhi to krna  h
  curr = curr->next;
 }
 delete curr->next;
 curr->next = NULL;
 return head;
}

node* deleteelement(node*head , int x){
  if(head == NULL) return head;
  node* curr = head;
  while(curr->next->data != x && curr->next!=NULL){
    curr= curr->next;
  }
  if(curr->next == NULL){return head;}
  delete curr->next;
  curr->next = curr->next->next;
  return head;
}

node* delpos(node*head , int x ,int pos){
  if(head == NULL) return NULL;
  node* curr = head;
  node* prev = NULL;
  for(int i = 1;i <= pos-1; i++){
    prev = curr;
    curr = curr->next;
  }
  prev->next = curr->next;
  delete curr;
  return head;

}
// this is the iterative solution
int search(node *head, int x)
{
 node *curr = head;
 int count = 1;
 while (curr != NULL)
 {
  if (curr->data == x)
   return count;
  else
  {
   curr = curr->next;
   count++;
  }
 }
 return -1;
} // tc o(n)  as o(1)

// this is the reccursive solution for searching an element

int searchrecc(node *head, int x, int count)
{
 if (head == NULL)
  return -1;
 if (head->data == x)
 {
  return count;
 }
 searchrecc(head->next, x, count + 1);
} // tc o(n) as o(n)

// the recc call can also be written as
int serachrecc2(node *head, int x)
{
 if (head == NULL)
  return -1;
 if (head->data == x)
  return 1;
 else
 {
  int res = serachrecc2(head, x);
  if (res == -1)
   return -1;
  else
   return (res + 1);
 }
}
int main()
{
 node *head = NULL;
 head = insertatbegin(head, 10); // TC O(1)
 head = insertatbegin(head, 20);
 head = insertatbegin(head, 30);
 head = insertatbegin(head, 40);
 head = insertatend(head, 50);
 head = insertatend(head, 60);
 head = insertatmiddle(head, 45, 4);
 head = deletehead(head); // TC O(1)
 head = deletetail(head); // TC O(n)
 cout << "the item to be searched is at pos : " << search(head, 51) << endl;
 cout << "the item to be searched is at pos : " << searchrecc(head, 50, 1) << endl;
 head = deleteelement(head , 51);
 rprint(head);
}