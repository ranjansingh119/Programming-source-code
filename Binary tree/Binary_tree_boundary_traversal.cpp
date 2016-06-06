#include <iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;


struct treenode{

 int data;
 struct treenode *left ,*right;

};

typedef struct treenode node;


node* newnode(int data){

 node* t = (node*)malloc(sizeof(node));
 t->data = data;
 t->left = NULL;
 t->right = NULL;

 return t;

}


void print_leftboundary(node* root){

 if(root){


    if(root->left){

        cout<<root->data<<endl;
        print_leftboundary(root->left);

    }

    else if(root->right){

        cout<<root->data<<endl;
        print_leftboundary(root->right);
    }
 }

}


void print_leaves(node* root){
 if(root){


    print_leaves(root->left);

    if(!root->left   &&  !root->right){
        cout<<root->data<<endl;
    }

    print_leaves(root->right);
 }


}


void print_rightboundary(node* root){

 if(root){


    if(root->right){

        print_rightboundary(root->right);
        cout<<root->data<<endl;

    }

    else if(root->left){
        print_rightboundary(root->left);
        cout<<root->data<<endl;
    }
 }


}


void print_boundary(node* root){

 if(root){
    cout<<root->data<<endl;

    print_leftboundary(root->left);

    print_leaves(root->left);
    print_leaves(root->right);

    print_rightboundary(root->right);

 }

}


int main(){

 struct treenode* root = newnode(20);

 root->left = newnode(8);
 root->right = newnode(22);

 root->left->left = newnode(4);
 root->left->right = newnode(12);
 root->left->right->right = newnode(14);
 root->left->right->left = newnode(10);

 root->right->right = newnode(25);


 print_boundary(root);

 return 0;
}
