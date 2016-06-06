#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define MAX 500


using namespace std;

struct node{

 int data;
  struct node* left;
  struct node* right;
};


struct node** create_queue(int* front, int* rear);
void enqueue(struct node** queue, int* rear, struct node* newnode);
struct node* dequeue(struct node** queue, int* front);


void printlevelorder(struct node* root){

 int front, rear;
 struct node** queue = create_queue(&front, &rear);
 struct node* temp = root;

 while(temp!=NULL){

     cout<<temp->data<<" ";

     if(temp->left!=NULL)
        enqueue(queue, &rear, temp->left);

     if(temp->right!=NULL)
        enqueue(queue, &rear, temp->right);

     temp = dequeue(queue, &front);

 }


}

struct node** create_queue(int* front, int* rear){

 struct node** queue = (struct node** )malloc(sizeof(struct node*)*MAX);

 *front = *rear = 0;
 return queue;

}


void enqueue(struct node** queue, int* rear, struct node* newnode){
    queue[*rear] = newnode;
    (*rear)++;

}


struct node* dequeue(struct node** queue, int* front){

   (*front)++;
    return (queue[*front -1]);

}


struct node* newnode(int data){

 struct node* n = (struct node*)malloc(sizeof(struct node));
 n->data = data;
 n->left = NULL;
 n->right = NULL;

 return n;
}


int main(){

 struct node* root = newnode(10);
 root->left = newnode(4);
 root->right = newnode(12);
 root->left->right = newnode(5);
 root->left->left = newnode(2);

 root->right->left = newnode(11);
 root->right->right = newnode(14);
 root->left->left->left = newnode(1);

 printlevelorder(root);

 return 0;
 getchar();

}
