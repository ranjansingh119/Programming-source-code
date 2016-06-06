#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


struct node{

int data;
struct node *left, *right;

};


struct node* newnode(int data){

 struct node* m = (struct node* )malloc(sizeof(struct node));
 m->data = data;
 m->left = m->right = NULL;

 return m;
}


void inorder_traversal(struct node* r1){

 if(r1==NULL)
    return;

 inorder_traversal(r1->left);
 cout<<r1->data<<" ";
 inorder_traversal(r1->right);

}


void mirror_tree(struct node* r){

 if(r==NULL)
    return;

 else{
    struct node* temp=NULL;

    mirror_tree(r->left);
    mirror_tree(r->right);

    temp = r->left;
    r->left = r->right;
    r->right = temp;
 }

}



int main(){

 struct node* root = newnode(10);
 root->left = newnode(6);
 root->right = newnode(13);
 root->left->left = newnode(4);
 root->left->right = newnode(8);

 root->right->left = newnode(11);
 root->right->right = newnode(14);

 cout<<"\n Inorder traversal of original tree";
 inorder_traversal(root);

 mirror_tree(root);

 cout<<"\n Inorder traversal of mirrored tree";
 inorder_traversal(root);

 return 0;
}

