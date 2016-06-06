/*Taking an array and converting it into a binary search tree with along with converting th binary numbers
into decimal numbers */


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define row 4
#define col 3

using namespace std;

struct tnode{
 int data;
 int roww;
 struct tnode* left;
 struct tnode* right;

};

struct tnode* newnode(int data, int roww){
 struct tnode* temp  = (struct tnode*)malloc(sizeof(struct tnode));
 temp->data = data;
 temp->roww = roww;
 temp->left = temp->right =NULL;

 return temp;
}

void print_tree(struct tnode* r);


struct tnode* insert_into_bst(struct tnode* node, int data, int roww)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newnode(data, roww);

    if (data < node->data)
        node->left  = insert_into_bst(node->left, data, roww);
          else if (data > node->data)
            node->right = insert_into_bst(node->right, data, roww);


    return node;
}


void arr_to_decimal(int arr[][col] ){
int i, sum[4], temp;
int power;

for( i=0; i<row; i++){
    temp =0;
    power =2;
    for(int j=0;j<col; j++){

        temp += pow(2,power)* arr[i][j];
        power--;
    }
    sum[i] = temp;
 }

  struct tnode* root = newnode(sum[0], 0);
  for(i=1;i<4;i++){
   insert_into_bst(root, sum[i], i);
  }

  print_tree(root);
}


void print_tree(struct tnode* r){

        if (r == NULL)
          return;

     /* first print data of node */
     cout<<r->data<<" "<<r->roww<<endl;

     /* then recur on left sutree */
     print_tree(r->left);

     /* now recur on right subtree */
     print_tree(r->right);
}


int main(){

 int arr[][3] = {{1,0,1}, {1,0,0}, {1,1,0}, {1,1,1} };

 arr_to_decimal(arr);

 return 0;
 getchar();
}
