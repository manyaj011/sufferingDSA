#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 int data;
 node *next = NULL;
 node(int x)
 {
  data = x;
  next = NULL;
 }
};
void print(node *head)
{
 if (head == NULL)
  cout << "no node present" << endl;
 node *curr = head;
 do
 { // do while lgane se ek hi el ho jb tb adv h kunki uska next head h to ek baar to print hona pdega while lgate to curr bhi head h aur curr->next bhi head h
  cout << curr->data << " ";
  curr = curr->next;
 } while (curr != head);
}
int main()
{
 node *head = new node(10);
 head->next = new node(20);
 head->next->next = new node(30);
 head->next->next->next = head;
 print(head);
 return 0;
}