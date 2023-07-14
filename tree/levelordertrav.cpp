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
int height(node *root)
{
 if (root == NULL)
  return 0;
 return max(height(root->left), height(root->right)) + 1;
}
void levelorder1(node *root, int k)
{
 if (root == NULL)
  return;
 if (k == 0)
  cout << root->key << " ";
 else
 {
  levelorder1(root->left, k - 1);
  levelorder1(root->right, k - 1);
 }
}

// appraoch by using queue
void levelorder2(node *root)
{
 queue<node *> q; // why * beacuse qw r pushing root
 q.push(root);
 while (!q.empty())
 {
  node *curr = q.front();
  q.pop();
  cout << curr->key << " ";
  if (curr->left != NULL)
  {
   q.push(curr->left);
  }
  if (curr->right != NULL)
  {
   q.push(curr->right);
  }
 }
}

// level order traversal line by line
void linebyline(node *root)
{
 queue<node *> q;
 q.push(root);
 q.push(NULL);
 while (q.size() > 1)
 {
  node *curr = q.front();
  q.pop();
  if (curr == NULL)
  {
   cout << endl;
   q.push(NULL);
   continue;
  }
  cout << curr->key << " ";
  if (curr->left != NULL)
   q.push(curr->left);
  if (curr->right != NULL)
   q.push(curr->right);
 }
}
// another way of line by line print of level order traversal
void linebyline2(node *root)
{
 queue<node *> q;
 q.push(root);
 while(q.empty() == false)
 {
 int count = q.size();
 for (int i = 0; i < count; i++)
 {
  node *curr = q.front();
  q.pop();
  cout << curr->key << " ";
  if (curr->left != NULL)
   q.push(curr->left);
  if (curr->right != NULL)
   q.push(curr->right);
 }
 cout<<endl;
 }
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 int h = height(root);
 for (int i = 0; i < 3; i++)
 {
  levelorder1(root, i);
  cout << endl;
 }
 // but this is not eff because here o(n) tc for height then o(n) for each call obviously less than o (n ) at every call except last but total more then o(n) for level order
 // and level order  plus height total will be more than o(n)
 levelorder2(root);
 cout << endl;
 linebyline(root);
 cout<<endl;
 linebyline2(root);
}