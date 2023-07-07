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
void printnodesatdistk(node *root, int k)
{
 if (root == NULL)
  return;
 if (k == 0)
  cout << root->key << " ";
 else
 {
  printnodesatdistk(root->left, k - 1);
  printnodesatdistk(root->right, k - 1);
 }
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 int k;
 cout << "enter the dist at which you want to print the nodes:";
 cin >> k;
 printnodesatdistk(root, k);
}