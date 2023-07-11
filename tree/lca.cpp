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

bool findpath(node *root, vector<node *> &p, int n)
{
 if (root == NULL)
  return false;
 p.push_back(root);
 if (root->key == n)
  return true;
 if (findpath(root->left, p, n) || findpath(root->right, p, n))
  return true;
 p.pop_back();
 return false;
}
node *lca(node *root, int n1, int n2)
{
 vector<node *> path1, path2;
 if (findpath(root, path1, n1) == false || findpath(root, path2, n2) == false)
 {
  return NULL;
 }
 for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
 {

  if (path1[i + 1] != path2[i + 1])
  {
   return path1[i];
  }
  return NULL;
 }
}

// this is the eff solution

node *eff(node *root, int n1, int n2)
{
 if (root == NULL)
  return NULL;
 if (root->key == n1 || root->key == n2)
 {
  return root;
 }
 node *lca1 = eff(root->left, n1, n2);
 node *lca2 = eff(root->right, n1, n2);
 if (lca1 != NULL && lca2 != NULL)
 {
  return root;
 }
 else if (lca1 != NULL)
 {
  return lca1;
 }
 else
 {
  return lca2;
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

 // cout << lca(root, 10, 7);
 node*res = eff(root , 10,7);
 cout<<res->key;
 // cout<<val->key;
}