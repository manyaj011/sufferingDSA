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
int max_level = 0;
void leftview(node *root, int level)
{
 if (root == NULL)
  return;
 if (max_level < level)
 {
  cout << root->key << " ";
  max_level = level;
 }
 leftview(root->left, level + 1);
 leftview(root->right, level + 1);
}
// we basically need to do the preorder traversal and maintain 2 varibales
void leftviewofbinarytree(node *root)
{
 leftview(root, 1); // we consider root at level 1
}

// itervative sol:
void printleft(node *root)
{
 queue<node *> q;
 q.push(root);
 while (!q.empty())
 {

  int count = q.size();
  for (int i = 0; i < count; i++)
  {
   node *curr = q.front();
   q.pop();
   if (i == 0)
    cout << curr->key << " ";
   if (curr->left != NULL)
    q.push(curr->left);
   if (curr->right != NULL)
    q.push(curr->right);
  }
 }
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 leftviewofbinarytree(root);
 cout<<endl;
 printleft(root);
}