#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 int data;
 node *next;
 bool visited;
 node(int x)
 {
  data = x;
  next = NULL;
  visited = false;
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

bool detectloop(node *head)
{
 if (head == NULL)
  return false;
 node *curr = head;
 while (curr != NULL)
 {
  if (curr->visited == false)
  {
   curr->visited = true;
   curr = curr->next;
  }
  else
  {
   return true;
  }
 }
 return false;
}

bool detectloop2(node *head)
{
 node *temp = new node(0);
 node *curr = head;
 while (curr != NULL)
 {
  if (curr->next == NULL)
   return false;
  if (curr->next == temp)
   return true;
  else
  {
   node *curr_next = curr_next;
   curr_next = temp;
   curr = curr->next;
  }
 }
}

// using hashing

bool detecthashing(node *head)
{
 unordered_set<node *> s;
 for (node *curr = head; curr != NULL; curr = curr->next)
 {
  if (s.find(curr) != s.end())
   return true;
  s.insert(curr);
 }
 return false;
}

// detect loop using floyd's detection loop
bool detectfloyd(node *head)
{
 node *slow_p = head;
 node *fast_p = head;
 while (fast_p != NULL && fast_p->next != NULL)
 {
  slow_p = slow_p->next;
  fast_p = fast_p->next->next;
  if (slow_p == fast_p) // ye cond yhi aaegi kunki agr pehle aai to vo to intial case m equal hi ho jaega na cse both are head
   return true;
 }
 return false;
}

// detect & remove loop in a linked list
node *detectanddelete(node *head)
{
 node *slow = head;
 node *fast = head;
 while (fast != NULL && fast->next != NULL)
 {
  slow = slow->next;
  fast = fast->next->next;
  if (slow == fast)
  {
   break;
  }
 }
 if (slow != fast)
 {
  return head;
 }
 slow = head;
 while (slow->next != fast->next)
 { // jese hi slow ka next fast ke next ke eqaul hoga mtlb dono n steps cover kr liye to ab vo next loop m start of node p phunch jaenge isliye fase->ext ko NULL krdo
  slow = slow->next;
  fast = fast->next;
 }
 fast->next = NULL;
 return head;
}

// to find the length of the loop
int lengthofloop(node *head)
{
 node *slow = head;
 node *fast = head;
 while (fast != NULL && fast->next != NULL)
 {
  slow = slow->next;
  fast = fast->next->next;
  if (slow == fast)
  {
   break;
  }
 }
 if (slow != fast)
 {
  return 0;
 }
 int count = 0 ;
 while (fast->next != slow){
  fast = fast->next;
  count++;
 }
 return count+1;
}



 //find the first node of the loop

 node* findfirstnode(node *head){
  node* slow = head;
  node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
   slow = slow->next;
   fast = fast->next->next;
   if(slow == fast)
   {
    break;
   }
  }
  if(slow!=fast){
   return NULL;
  }
  slow = head;
  while(slow->next != fast->next){
   slow = slow->next;
   fast = fast->next;
  }
  return fast->next;

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
 head->next->next->next->next->next = head->next;
 if (detecthashing(head))
 {
  cout << "loop is present" << endl;
 }
 else
 {
  cout << " not present" << endl;
 }
 cout << endl;
 head = detectanddelete(head);
 if (detecthashing(head))
 {
  cout << "loop is present" << endl;
 }
 else
 {
  cout << " not present" << endl;
 }
 cout<<lengthofloop(head)<<endl;
 node* temp = findfirstnode(head);
 cout<<temp->data<<" ";
 // print(head);
}