#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
 Node *next, *random;
 int data;
 Node(int x)
 {
  next = random = NULL;
  data = x;
 }
};

// NAIVE METHOD

Node *clone(Node *head)
{
 unordered_map<Node *, Node *> m;
 for (Node *curr = head; curr != NULL; curr = curr->next)
 {
  m[curr] = new Node(curr->data);
 }
 for (Node *curr = head; curr != NULL; curr = curr->next)
 {
  m[curr]->next = m[curr->next]; // ye LHS m hmari nyi linked list bnti jaa ri h jo  //ye to unordered hot h na phr ie kya ptaa 10 ko 5 se hi coneect hona h aur hm seedha curr->next ku nhi likh skte??
  m[curr]->random = m[curr->random];
 }
 return head;
 // why m[head]??
}
Node *clonelinkedlist(Node *head)
{
 for (Node *curr = head; curr != NULL; curr = curr->next) // through this we inserted similar  nodes in between the original nodes
 {
  Node *next = curr->next;
  curr->next = new Node(curr->data);
  curr->next->next = next;
  curr = next;
 }
 for (Node *curr = head; curr != NULL; curr = curr->next->next)
 { // now we have to set the random pointers . here we don't have to check that if curr->next is NULL or not because linked list even hi rhegi id curr exist to curr->next will als exist
  curr->next->random = curr->random->next;
 }

 // now we have to separate both the linked lists
 Node *h2 = head->next;
 Node *clone = h2;
 for (Node *curr = head; curr != NULL; curr = curr->next)
 {
  curr->next = curr->next->next;
  clone->next = clone->next ? clone->next->next : NULL;
  clone = clone->next;
 }
 return h2;
}
void print(Node *head)
{
 if (head == NULL)
  cout << "no item" << endl;
 else
 {
  Node *curr = head;
  while (curr != NULL)
  {
   cout << curr->data << " ";
   curr = curr->next;
  }
 }
}
int main()
{
 Node *head = new Node(10);
 head->next = new Node(5);
 head->next->next = new Node(20);
 head->next->next->next = new Node(15);
 head->next->next->next->next = new Node(20);

 head->random = head->next->next;
 head->next->random = head->next->next->next;
 head->next->next->random = head;
 head->next->next->next->random = head->next->next;
 head->next->next->next->next->random = head->next->next->next;
}