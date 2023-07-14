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
bool childrensumoprop(node *root)
{
 if (root == NULL)
  return true;
 if (root->left == NULL && root->right == NULL)
  return true;
 int sum = 0;
 if (root->right != NULL)
  sum += root->right->key;
 if (root->left != NULL)
  sum += root->left->key;
 return (sum == root->key && childrensumoprop(root->left) && childrensumoprop(root->right));
}

//discuss the iterative
bool iterative(node *root)
{

 if (root == NULL)
  return true;
 if (root->left == NULL && root->right == NULL)
  return true;
 queue<node*>q;
 q.push(root);
 while(!q.empty()){
  int sum = 0;
  if (root->left != NULL);
 }
 
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(2);
 root->right->left = new node(40);
 root->right->right = new node(2);
 cout << childrensumoprop(root);
}