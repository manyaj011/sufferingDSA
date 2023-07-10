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

int height(node *root){
 if(root == NULL) return 0;
 return 1 + max(height(root->left), height(root->right));
}
int diameter(node *root)
{
 if(root == NULL) return 0;
 int d1 = 1 + height(root->left) + height(root->right);
 int d2 = diameter(root->left);
 int d3 = diameter(root->right);
 return max(d1 , max(d2,d3));
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

 cout<<diameter(root);
}