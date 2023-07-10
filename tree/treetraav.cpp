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
   if (reverse) // reverse true hone p reversed print hoga
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
    cout << s.top() << " ";
    s.pop();
   }
  }
  reverse = !reverse;
  cout << endl;
 }
}

// this is method 2 with btter TC
void spiralform(node *root)
{
 stack<node *> s1;
 stack<node *> s2;
 s1.push(root);
 while (!s1.empty() || !s2.empty())
 {
  while (s1.empty() == false)
  {
   // node *curr = s1.top();
   // cout << curr->key<<" ";
   // s1.pop();
   // if (curr->left != NULL)
   //  s2.push(curr->left);
   // if (curr->right != NULL)
   //  s2.push(curr->right);

   // this is the line by line display of nodes in tree spiral form;
   int s = s1.size();
   for (int i = 0; i < s; i++)
   {
    node *curr = s1.top();
    cout << curr->key << " ";
    s1.pop();
    if (curr->left != NULL)
     s2.push(curr->left);
    if (curr->right != NULL)
     s2.push(curr->right);
   }
   cout << endl;
  }

  while (s2.empty() == false)
  {
   // node *curr = s2.top();
   // cout << curr->key<<" ";
   // s2.pop();
   // if (curr->right != NULL)
   //  s1.push(curr->right);
   // if (curr->left != NULL)
   //  s1.push(curr->left);

   int s = s2.size();
   for (int i = 0; i < s; i++)
   {
    node *curr = s2.top();
    cout << curr->key << " ";
    s2.pop();
    if (curr->right != NULL)
     s1.push(curr->right);
    if (curr->left != NULL)
     s1.push(curr->left);
   }
   cout << endl;
  }
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

 spiralform(root);
}