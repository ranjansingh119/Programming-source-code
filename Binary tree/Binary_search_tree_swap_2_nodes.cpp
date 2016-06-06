#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


struct node
{
    int data;
    struct node *left, *right;
};


struct node* newnode(int data)
{
    struct node* n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}


void swap( int* node1, int* node2 )
{
    int t = *node1;
    *node1 = *node2;
    *node2 = t;
}

void swap_nodes_of_bst( struct node* root, struct node** first, struct node** prev, struct node** middle, struct node** last)
{
    if( root )
    {

        swap_nodes_of_bst( root->left, first, prev, middle, last );


        if (*prev && root->data < (*prev)->data)
        {

            if ( !*first )
            {
                *first = *prev;
                *middle = root;
            }

            else
                *last = root;
        }


        *prev = root;


        swap_nodes_of_bst( root->right, first, prev, middle, last );
    }
}


void modify_bst( struct node* root )
{

    struct node *first=NULL;
    struct node *middle=NULL;
    struct node *last=NULL;
    struct node *prev=NULL;


    swap_nodes_of_bst( root, &first, &prev, &middle, &last );


    if( first && last )
        swap( &(first->data), &(last->data) );
    else if( first && middle )
        swap( &(first->data), &(middle->data) );


}


void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}


int main()
{


    struct node *root = newnode(6);
    root->left        = newnode(10);
    root->right       = newnode(2);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(12);
    root->right->left = newnode(7);

    printf("Traversal of the tree \n");
    printInorder(root);

    modify_bst(root);

    printf("\n Traversal of the tree after swapping nodes: \n");
    printInorder(root);

    return 0;
}
