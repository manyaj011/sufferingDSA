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
node *insertatbegin(node *head, int x)
{
 node *temp = new node(x);

 if (head == NULL)
 {
  temp->next = temp;
  temp->prev = temp;
  return temp;
 }
 node *curr = head;
 while (curr->next != head)
 {
  curr = curr->next;
 }

 head->prev = temp;
 temp->next = head;
 temp->prev = curr;
 curr->next = temp;
 return temp; // incase of insert at end here instead of returning temp return head as that will be head in this case

 // without loop

 // temp->prev = head->prev;
 // temp->next = head;
 // head->prev->next = temp;
 // head->prev = temp;
 // return temp;
}
void print(node *head)
{
 node *curr = head;

 do
 {
  cout << curr->data << " ";
  curr = curr->next;
 } while (curr != head);
}

int main()
{
 node *head = NULL;
 head = insertatbegin(head, 10);
 head = insertatbegin(head, 20);
 head = insertatbegin(head, 30);
 print(head);
}