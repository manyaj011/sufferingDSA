// we need to find merge two sorted linked list

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

node *mergetwosorted(node *a, node *b)
{
 if (a == NULL)
  return b;
 if (b == NULL)
  return a;
 node *head, *tail = NULL;
 if (a->data <= b->data)
 {
  head = tail = a;
  a = a->next;
 }
 else
 {
  head = tail = b;
  b = b->next;
 }
 while (a != NULL && b != NULL)
 {
  if (a->data <= b->data)
  {
   tail->next = a;
   tail = a;
   a = a->next;
  }
  else
  {
   tail->next = b;
   tail = b;
   b = b->next;
  }
 }
 if (a == NULL)
  tail->next = b;
 else
  tail->next = a;

 return head;
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


//tc o(n) as o(1)
int main()
{
 node *head1 = NULL;
 head1 = insertnode(head1, 10);
 head1 = insertnode(head1, 20);
 head1 = insertnode(head1, 30);
 head1 = insertnode(head1, 40);
 head1 = insertnode(head1, 50);
 head1 = insertnode(head1, 60);
 node *head2 = NULL;
 head2 = insertnode(head2, 5);
 head2 = insertnode(head2, 15);
 head2 = insertnode(head2, 25);
 head2 = insertnode(head2, 35);
 head2 = insertnode(head2, 45);
 node *head = mergetwosorted(head1, head2);

 print(head);
}