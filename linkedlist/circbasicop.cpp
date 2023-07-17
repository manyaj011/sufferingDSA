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
  temp->next = temp;
  return temp;
 }
 node *curr = head;
 while (curr->next != head)
 {
  curr = curr->next;
 }
 temp->next = head;
 curr->next = temp;
 return temp;
} // tc o(n)

void insertbegintail(node *&tail, int x, node *&head)
{
 node *temp = new node(x);
 if (tail == NULL)
 {
  temp->next = temp;
  tail = temp;
  head = temp;
 }
 node *t = tail->next;
 tail->next = temp;
 temp->next = t;
 head = temp;
}

// another method

void insertbegin(node *&head, int x)
{
 node *temp = new node(x);
 if (head == NULL)
 {
  temp->next = temp;
  head = temp;
 }
 temp->next = head->next;
 head->next = temp;
 int t = head->data;
 head->data = temp->data;
 temp->data = t;
}

//insert at end

//deletehead
//deleteend
void print(node *head)
{
 if (head == NULL)
  cout << "no node";
 node *curr = head;
 do
 {
  cout << curr->data << " ";
  curr = curr->next;
 } while (curr != head);
} // tc o(n)

int main()
{
 node *tail = NULL;
 node *head = NULL;
 // head = insertatbegin(head, 10);
 // head = insertatbegin(head, 20);
 // head = insertatbegin(head, 30);
 insertbegintail(tail, 10, head);
 insertbegintail(tail, 20, head);
 insertbegintail(tail, 30, head);
 print(head);
}