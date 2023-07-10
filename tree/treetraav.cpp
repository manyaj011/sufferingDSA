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
void printspiral(node *root)
{
 if (root == NULL)
  return;
 queue<node *> q;
 stack<int> s;
 bool reverse = false;
 q.push(root);
 while (!q.empty())
 {
  int count = q.size();
  for (int i = 0; i < count; i++)
  {
   node *curr = q.front();
   q.pop();
   if (reverse)
   {
    s.push(curr->key);
   }
   else
   {
    cout << curr->key << " ";
   }
   if (curr->left != NULL)
    q.push(curr->left);
   if (curr->right != NULL)
    q.push(curr->right);
  }
  if (reverse)
  {
   while (s.empty() == false)
   {
    cout << s.top()<<" ";
    s.pop();
   }
  }
  reverse = !reverse;
  cout << endl;
 }
}

//this is method 2 with btter TC
void spiralform(node *root){
 stack<int>s1;
 stack<int>s2;
 s1.push(root->key);
 while(s1.empty() == false){
  s1.
 }
 while(s2.empty() == false){

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
 root->left->left->right = new node(8);
 root->right->left->left = new node(10);
 root->right->left->right = new node(11);

 printspiral(root);
}