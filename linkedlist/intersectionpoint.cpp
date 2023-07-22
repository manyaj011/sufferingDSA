// we need to find the intesection point of two linked list
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

int intersection(node *head1, node *head2)
{
 if (head1 == NULL || head2 == NULL)
  return -1;

 unordered_set<node *> s;
 for (node *curr = head1; curr != NULL; curr = curr->next)
 {
  s.insert(curr);
 }
 for (node *curr = head2; curr != NULL; curr = curr->next)
 {
  if (s.find(curr) != s.end())
  {
   return curr->data;
  }
 }
 return -1;
 ;
}

int intersec(node *head1, node *head2)
{

 if (head1 == NULL || head2 == NULL)
  return -1;
 node *curr1 = head1;
 node *curr2 = head2;
 int count1 = 0, count2 = 0;

 while (curr1 != NULL)
 {
  count1++;
  curr1 = curr1->next;
 }
 while (curr2 != NULL)
 {
  count2++;
  curr2 = curr2->next;
 }

 int x = count1 - count2;
 curr1 = head1;
 curr2 = head2;
 if (x == 0)
  return head1->data;
 else if (x > 0)
 {
  while (x > 0)
  {
   curr1 = curr1->next;
   x--;
  }
 }
 else
 {
  while (x > 0)
  {
   curr2 = curr2->next;
   x--;
  }
 }
 while (curr1 != NULL && curr1 != NULL)
 {
  if (curr1 == curr2)
  {
   return curr1->data;
  }
  curr1 = curr1->next;
  curr2 = curr2->next;
 }
 return -1;
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
 node *head1 = NULL;
 head1 = insertnode(head1, 10);
 head1 = insertnode(head1, 20);
 head1 = insertnode(head1, 30);
 head1 = insertnode(head1, 40);
 head1 = insertnode(head1, 50);
 head1 = insertnode(head1, 60);
 node *head2 = NULL;
 head2 = insertnode(head2, 1);
 head2 = insertnode(head2, 2);
 head2->next->next = head1->next->next;
 head2->next->next->next = head1->next->next->next;
 head2->next->next->next->next = head1->next->next->next->next;
 head2->next->next->next->next->next = head1->next->next->next->next->next;
 cout << intersection(head1, head2);
 // print(head);
}