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
node *insertatbegin(node *head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
 {
  return temp;
 }
 temp->next = head;
 return temp;
}

node *sorted(node *head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
 {
  return temp;
 }
 if (x <= head->data)
 {
  temp->next = head;
  return temp;
 }

 // yhaan do cond m head change hoga ek to jb initially head null ho aur doosra jb smallest element insert ho rha ho
 node *curr = head;
 while (curr->next != NULL && curr->next->data <= x) // imp cond  h curr->next!=NULL ye kon check krega last m insert krna ho to phr to garbage value se compare ho jaega
 {
  curr = curr->next;
 }
 temp->next = curr->next;
 curr->next = temp;
 return head;
}
// tc o(pos) //pos is where ele is to be inserted
void print(node *head)
{
 node *curr = head;
 while (curr != NULL)
 {
  cout << curr->data << " ";
  curr = curr->next;
 }
}
int main()
{
 node *head = NULL;
 head = insertatbegin(head, 30);
 head = insertatbegin(head, 20);
 head = insertatbegin(head, 10);
 head = sorted(head, 25);
 head = sorted(head, 5);
 head = sorted(head, 45);
 head->next->next->next->next = head->next;
 print(head);
}