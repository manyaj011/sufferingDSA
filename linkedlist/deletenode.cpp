//delete node with only pointer given to it

#include<bits/stdc++.h>
using namespace std;
class node{
 public:
 node* next;
 int data;
 node(int x){
  next = NULL;
  data = x;
 }
 
};

node* insertnode(node* head ,int x){
 node* temp = new node(x);
 
 if(head == NULL){
  return temp;
 }

 node* curr = head;
 while(curr->next!=NULL){
  curr = curr->next;
 }
 curr->next = temp;
 return head;
}

void deletenode(node *ptr){
 node* temp = ptr->next;
 ptr->data = ptr->next->data; //coying the data of ptr->next node into the ptr node cse hme vrna loop run krke ptr ki pos nikalni pdegi aur phr usme aage wali ode ko del kra pdega tc o(n)
 //but here the tc is o(1);
 ptr->next = temp->next;
 delete(temp);

}

void print(node* head){
 if(head == NULL) cout<<"no item"<<endl;
 else{
  node*curr = head;
  while(curr!=NULL){
   cout<<curr->data<<" ";
   curr = curr->next;
  }
 }
}
int main(){
 node* head = NULL;
 head = insertnode(head, 10);
 head = insertnode(head, 20);
 head = insertnode(head, 30);
 head = insertnode(head, 40);
 head = insertnode(head, 50);
 head = insertnode(head, 60);
 deletenode(head->next->next->next);
 print(head);

}