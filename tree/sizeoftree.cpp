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
// this is the reccursive solution
int getsize(node *root)
{
 if (root == NULL)
  return 0;
 return 1 + (getsize(root->left) + getsize(root->right));
}

// iterative solution
int getsize1(node *root)
{
 int count = 0;
 queue<node *> q;
 q.push(root);
 while (q.empty() == false)
 {
  count++;
  node *curr = q.front();
  q.pop();
  if (curr->left != NULL)
   q.push(curr->left);
  if (curr->right != NULL)
   q.push(curr->right);
 }
 return count;
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 cout << getsize(root) << endl;
 cout << getsize1(root) << endl;
}