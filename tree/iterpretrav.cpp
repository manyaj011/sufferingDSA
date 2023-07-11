#include <bits/stdc++.h>
using namespace std;

class node
{
public:
 int key;
 node *left;
 node *right;
 node(int k)
 {
  key = k;
  left = right = NULL;
 }
};

void iterpreorder(node *root){
 if(root == NULL) return;
 stack<node*>st;
 st.push(root);
 while(st.empty() == false){
  node *curr = st.top();
  cout<<st.top() <<" ";
  if(curr->right!=NULL)
   st.push(curr->right);
  if (curr->left != NULL)
   st.push(curr->left);
 }
}
 


int main()
{
 node *root = new node(1);
 root->left = new node(2);
 root->right = new node(3);
 root->left->left = new node(4);
 root->left->right = new node(5);
 root->right->left = new node(6);
 root->right->right = new node(7);
 root->left->left->left = new node(8);
 root->left->left->right = new node(9);
 root->right->left->left = new node(10);
 root->right->left->right = new node(11);

 iterpreorder(root);
}