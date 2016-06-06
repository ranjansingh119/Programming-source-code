#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct tnode{

 int data;
 struct tnode* left;
 struct tnode* right;

};

struct tnode* newnode(int data);
int maximum(int array[], int s, int last);


struct tnode* create_special_tree(int arr[], int start, int end){

 if(start>end)
    return NULL;

 int max_element_index = maximum(arr, start, end);
 struct tnode* root = newnode(arr[max_element_index]);

 if(start==end)
    return root;

 root->left = create_special_tree(arr, start, max_element_index-1);
 root->right = create_special_tree(arr, max_element_index+1, end);


 return root;
}


int maximum(int array[], int s, int last){
 int max = array[s];
 int max_index = s;

 for(int i=s+1; i<=last; i++){

    if(array[i]>max){
        max = array[i];
        max_index = i;
    }
 }

 return max_index;
}



struct tnode* newnode(int data){

struct tnode* new_node = (struct tnode*) malloc (sizeof(struct tnode));
new_node->data = data;
new_node->left = new_node->right = NULL;

return new_node;
}


void inorder_display(struct tnode* root){

 if(root==NULL){
      return;
 }

   inorder_display(root->left);
    cout<<root->data<<" ";
    inorder_display(root->right);
}


int main(){

 int arr[] = {5, 10, 40, 30, 28};
 int size = sizeof(arr)/ sizeof(arr[0]);

 struct tnode* root = create_special_tree(arr, 0, size-1);

 cout<<"The inorder traversal of the given tree :"<<endl;
 inorder_display(root);

 return 0;
}
