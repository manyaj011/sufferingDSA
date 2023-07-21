// segregate even and odd nodes first even then odd elements

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

// naive method
// void segregate_even_odd_nodes(node *head)
// {
//  if (head == NULL)
//   return;
//  node *curr = head;
//  node *end = head;
//  while (end->next != NULL)
//  {
//   end = end->next;
//  }
//  if (curr->next->data % 2 != 0)
//  {
//   node *temp = curr;
//   end->next = curr;
//   end = ;
//   curr->next = curr->next->next
//  }
// }

// optimal approach

node *segregate(node *head)
{
 node *os = NULL;
 node *oe = NULL;
 node *es = NULL;
 node *ee = NULL;

 if (head == NULL)
  return NULL;
 for (node *curr = head; curr != NULL; curr = curr->next)
 {
  int x = curr->data;
  if (x % 2 == 0)
  {
   if (es == NULL)
   {
    es = ee = curr;
   }
   else
   {
    ee->next = curr;
    ee = ee->next;
   }
  }
  else
  {
   if (os == NULL)
   {
    os = oe = curr;
   }
   else
   {
    oe->next = curr;
    oe = oe->next;
   }
  }
 }
 if (os == NULL || es == NULL)
 { // this case is when the linked list is either all even or all odd
  return head;
 }
 ee->next = os;
 oe->next = NULL;
 return es;
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
 head = insertnode(head, 1);
 head = insertnode(head, 2);
 head = insertnode(head, 3);
 head = insertnode(head, 4);
 head = insertnode(head, 5);
 head = insertnode(head, 6);
 print(head);
 cout << endl;
 node *temp = segregate(head);
 print(temp);
}