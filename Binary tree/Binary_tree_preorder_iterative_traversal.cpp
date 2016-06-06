#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct node{

int data;
struct node* left;
struct node* right;

};


void preorder_traversal(struct node* root);


void preorder_traversal(struct node* root){

 if(root==NULL)
    return;

 stack<struct node*> node_st;
 node_st.push(root);


  while(!node_st.empty()){

   struct node* st = node_st.top();
   cout<<st->data<<" ";
   node_st.pop();

   if(st->right!=NULL)
    node_st.push(st->right);

   if(st->left!=NULL)
    node_st.push(st->left);


 }
}


struct node* newnode(int data){

 struct node* temp = (struct node* )malloc(sizeof(struct node));
 temp->data = data;
 temp->left = NULL;
 temp->right = NULL;

 return (temp);
}


int main(){

struct node* root = newnode(9);
root->left = newnode(5);
root->right = newnode(11);

root->left->left = newnode(3);
root->left->right = newnode(6);
root->right->left = newnode(10);
root->right->right = newnode(13);

preorder_traversal(root);

return 0;
getchar();
}
