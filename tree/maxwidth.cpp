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
int maxwidth(node *root){
 if(root == NULL) return 0;
 queue<node*>q;
 q.push(root);
 int res = 0;
 while(!q.empty()){
  int count = q.size();
  res = max(res,count);
  for (int i = 0; i < count; i++)
  {
   /* code */
   node *curr = q.front();
   q.pop();
   // cout<<curr->key;
   if(curr->left!=NULL)
    q.push(curr->left);
   if (curr->right != NULL)
    q.push(curr->right);
  }
 }
 return res;
}
int main()
{
 node *root = new node(10);
 root->left = new node(20);
 root->right = new node(30);
 root->left->left = new node(40);
 root->left->right = new node(50);
 // root->right->left = new node(40);
 root->right->right = new node(60);
 root->left->left->left = new node(80);
 cout<<maxwidth(root);
}