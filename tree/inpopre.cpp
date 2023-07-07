#include<bits/stdc++.h>
using namespace std;
class node{
 public:
  int key ;
  node *left;
  node *right;
  node(int k){
   key = k;
   left = right = NULL;
 }
};
void inorder(node *root)
{
 if (root != NULL)
 {
   inorder(root->left);
   cout << root->key << " ";
   inorder(root->right);
 }
}
void preorder(node *root)
{
 if (root != NULL)
 {
   cout << root->key << " ";
   preorder(root->left);
   preorder(root->right);
 }
}
void postorder(node *root)
{
 if (root != NULL)
 {
   postorder(root->left);
   postorder(root->right);
   cout << root->key << " ";
 }
}
int main(){
 node *root = new node(10);
 root -> left = new node(20);
 root -> right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 cout<<"the inorder traversal"<<endl;
 inorder(root);
 cout<<endl<<"the preorder traversal"<<endl;
 preorder(root);
 cout<<endl<<"the postorder traversal"<<endl;
 postorder(root);
}