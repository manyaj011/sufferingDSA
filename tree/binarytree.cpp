//this the basic implementation of tree
#include<bits/stdc++.h>
using namespace std;
class node{
 public:
  int key;
  node* left;
  node* right;
  node(int k){
   key = k;
   left = right = NULL;
  }
};
int main(){
 node *root = new node(10);  //datatype varibale = new datatype(value);
 root->left = new node(20);
 root->right = new node(30);
 root->left->left = new node(40);
 //for empty tree we can directy write
 //node *root = NULL;
}