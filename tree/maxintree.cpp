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

// reccursive solution
int maxi(node *root)
{
 if (root == NULL)
  return INT_MIN;
 return max(root->key, max(maxi(root->left), maxi(root->right)));
}

// the iterative solution
int maxi1(node *root)
{
 queue<node *> q;
 q.push(root);
 int res = INT_MIN;
 while (!q.empty())
 {
  node *curr = q.front();
  q.pop();
  res = max(curr->key, res);
  if (curr->left != NULL)
   q.push(curr->left);
  if (curr->right != NULL)
   q.push(curr->right);
 }
 return res;
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 cout << maxi(root) << endl;
 cout << maxi1(root) << endl;
}