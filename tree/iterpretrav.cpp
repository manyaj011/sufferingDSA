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

void iterpreorder(node *root)
{
 if (root == NULL)
  return;
 stack<node *> st;
 st.push(root);
 while (st.empty() == false)
 {
  node *curr = st.top();
  cout << curr->key << " ";
  st.pop(); // pop krna imp h na because tbhi to aage ki values access hongi
  if (curr->right != NULL)
   st.push(curr->right); // right pehle daala because usko baadme access krna h stack uses lifo

  if (curr->left != NULL)
   st.push(curr->left);
 }
}

// eff way
void effway(node *root)
{
 if(root == NULL) return; //initial con to check if the tree is empty
 stack<node *> st;
 node *curr = root;
 while (st.empty() == false || curr != NULL)
 {
  while (curr != NULL)
  {
   cout << curr->key << " ";
   if (curr->right != NULL)
    st.push(curr->right);
   curr = curr->left;
  }
  if(st.empty() == false)
  {
   curr = st.top();
   st.pop();
  }
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

 iterpreorder(root);cout<<endl;
 effway(root);
}