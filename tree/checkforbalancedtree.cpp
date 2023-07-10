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

//this is o(n^2) solution
bool balancedtree(node *root){
 if(root == NULL) return true;
 int lh = height(root->left);
 int rh = height(root->right);
 return (abs(lh - rh) <= 1 && balancedtree(root->left) && balancedtree(root->right));
}

//this is o(n) solution
int eff(node *root){
 if(root == NULL) return 0;
 int lh = eff(root->left) ;
 if(lh == -1) return -1;
 int rh = eff(root->right);
 if(rh == -1) return -1;
 if(abs(lh - rh) > 1) return -1; //this cond is checking if the diff bw the height is greater than 1 which is the reason for unbalanced tree..if yes then it returns -1 which indiactes it is unbalanced if not greater than 1 means then return the height of the subtree
 return max(lh,rh) + 1; //this calculates the height 
}
int main()
{
 node *root = new node(10);
 root->left = new node(8);
 root->right = new node(30);
 root->right->left = new node(40);
 root->right->right = new node(50);
 cout << balancedtree(root)<<endl;
 int x = eff(root);
 if(x == -1 ) cout<<"the tree is not balanced";
 else cout<<"the tree is balanced"; 
}