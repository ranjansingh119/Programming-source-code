#include<iostream>
#include<cstdio>


using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}



struct node *constructUtil(int p[], char pLN[], int *index_ptr, int n)
{
    int index = *index_ptr;

    if (index == n)
        return NULL;


    struct node *temp = newNode ( p[index] );
    (*index_ptr)++;


    if (pLN[index] == 'N')
    {
      temp->left  = constructUtil(p, pLN, index_ptr, n);
      temp->right = constructUtil(p, pLN, index_ptr, n);
    }

    return temp;
}


struct node *construct(int p[], char pLN[], int n)
{

    int index = 0;

    return constructUtil (p, pLN, &index, n);
}


void printInorder (struct node* node)
{
    if (node == NULL)
        return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}


int main()
{
    struct node *root = NULL;

    char pLN[] = {'N', 'N', 'L', 'L', 'L'};
    int p[] = {10, 30, 20, 5, 15};

    int n = sizeof(p)/sizeof(p[0]);

    root = construct(p, pLN, n);


    printf("Inorder Traversal of the Binary Tree: \n");
    printInorder (root);

    return 0;
}
