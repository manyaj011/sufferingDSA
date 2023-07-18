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

node *reverse(node *head)
{
 vector<int> arr;
 for (node *curr = head; curr != NULL; curr = curr->next)
 {
  arr.push_back(curr->data);
 }
 for (node *curr = head; curr != NULL; curr = curr->next)
 {
  curr->data = arr.back();
  arr.pop_back();
 }
 return head;
}
// this app uses O(n) traversals two times and O(n) auxillary space

// eff approach
node *reviter(node *head)
{
 node *prev = NULL;
 node *curr = head;
 while (curr != NULL)
 {
  node *next = curr->next;
  curr->next = prev;
  prev = curr; // prev curr se peeche rhega hmesha aur linkage m help krega phr uske baad prev ko ek aage aur curr ko ek aage
  curr = next;
 }
 return prev;
}

// tc O(n)
// as O(1)

node *reccrev1(node *head)
{
 if (head == NULL || head->next == NULL)
  return head;
 // this is cse ek hi ele hoga to usme rest_head and rest_tail will be NULL  jb rest->tail->next m to it will give segmentation fault because of NULL->next

 node *rest_head = reccrev1(head->next);
 node *rest_tail = head->next;
 rest_tail->next = head;
 head->next = NULL; // what is the need of this
 return rest_head;
}
// tc o(n)
// as o(n)
node *reccrev2(node *curr, node *prev) //this is almost same as reccursive iterative 
{
 if (curr == NULL)
  return prev;

 node *next = curr->next;
 curr->next = prev;
 return reccrev2(next, curr);
}

// tc o(n)
// as o(n)
int main()
{
 node *head = NULL;
 head = insertatbegin(head, 30);
 head = insertatbegin(head, 20);
 head = insertatbegin(head, 10);
 head = sorted(head, 25);
 head = sorted(head, 5);
 head = sorted(head, 45);
 head = reverse(head);
 head = reviter(head);
 head = reccrev2(head, NULL);
 print(head);
}