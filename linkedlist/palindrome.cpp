// delete node with only pointer given to it

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
 node *next;
 char data;
 node(char x)
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

bool palindrome(node* head){
 if(head == NULL) return true;
 stack<char>s;
 for(node* curr = head ; curr!=NULL ; curr = curr->next){
  s.push(curr->data);
 }
 node* curr = head;
 while(s.empty() == false && curr!=NULL){
  if(s.top() != curr->data){
   return false;
  }
  curr = curr->next;
  s.pop();
 }
 return true;
}

//this is the eff method

node* reverse(node* head ){
 if(head == NULL || head->next == NULL) return head;
 node* curr = head;
 node* prev = NULL;
 while(curr!=NULL){
  node* next = curr->next;
  curr->next = prev; 
  prev = curr;
  curr = next;
 }
 return prev;
}
bool palindrom(node* head){
 if(head == NULL) return true;
  
 //first find the middle element
 node* slow = head;
 node* fast = head;
 while(fast!=NULL && fast->next->next !=NULL){
  slow = slow->next;
  fast = fast->next->next;
 }

 // now reverse the elements after middle element

 node* rev = reverse(slow->next);

 //ab hmko first se element ko middle ke baad ke elements se compare krna h 
 node* curr =head;
 while(rev!=NULL){
  if(curr->data != rev->data){
   return false;
  }
  curr = curr->next;
  rev = rev->next;
 }
 return true;
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
 node *head = NULL;
 head = insertnode(head, 'g');
 head = insertnode(head, 'e');
 head = insertnode(head, 'e');
 head = insertnode(head, 'g');
 // head = insertnode(head, 50);
 // head = insertnode(head, 60);
 cout<<palindrom(head);
 // print(head);
}