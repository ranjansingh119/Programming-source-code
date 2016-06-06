#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node{

int data;
struct node *left, *right;
};

typedef struct node Node;

Node* newNode(int data){

Node* n = (Node*) malloc(sizeof(Node));
n->data = data;
n->left = n->right = NULL;

return n;
}

bool identical_trees(Node* h1, Node* h2){

  bool result = true;

  if(h1 == NULL && h2 == NULL){
    return result;
  }
   else if(h1!= NULL && h2!=NULL){

     if((h1->data == h2->data) && (identical_trees(h1->left, h2->left))  && (identical_trees(h1->right, h2->right)))
        return result;
     else
        return (!result);
   }

}


int main(){
 Node* root1 = newNode(12);
 Node* root2 = newNode(13);

 root1->left = newNode(10);
 root1->right = newNode(14);
 root1->left->right = newNode(11);

 root2->left = newNode(10);
 root2->right = newNode(14);
 root2->left->right = newNode(11);


 identical_trees(root1, root2) ? cout<<"Both trees are identical!" : cout<<"Both trees are not identical..";

 return 0;
}
