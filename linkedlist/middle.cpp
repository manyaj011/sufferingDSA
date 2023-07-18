// we need to find the middle of the linked list

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

void middle(node *head)
{
 int coun = 0;
 node *curr = head;
 while (curr != NULL)
 {
  coun++;
  curr = curr->next;
 }
 curr = head;
 for (int i = 0; i < coun / 2; i++)
 {
  curr = curr->next;
 }
 cout << curr->data << " ";
}


//eff approach
void middleele(node* head){
 if(head == NULL) return;
 node* slow = head;
 node* fast = head;
 while(fast!=NULL && fast->next !=NULL){
  slow = slow->next;
  fast = fast->next->next;
 }
 cout<<slow->data<<" ";
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
 print(head);
 cout << endl;
 middle(head);
 cout<<endl;
 middleele(head);
}