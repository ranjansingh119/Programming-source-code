#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;


struct treenode{

 int data;
 struct treenode* left;
 struct treenode* right;

};


struct treenode* newnode(int data){

 struct treenode* n = (struct treenode*) malloc(sizeof(struct treenode));
 n->data = data;
 n->left = NULL;
 n->right = NULL;

 return n;
}


void printGivenLevel(struct treenode* root, int level, int ltr);
int height(struct treenode* node);


void printspiral(struct treenode* root)
{
    int h = height(root);
    int i;

    /*ltr -> Left to Right. If this variable is set,
      then the given level is traverseed from left to right. */
    bool ltr = false;
    for(i=1; i<=h; i++)
    {
        printGivenLevel(root, i, ltr);

        /*Revert ltr to traverse next level in oppposite order*/
        ltr = !ltr;
    }
}

/* Print nodes at a given level */
void printGivenLevel(struct treenode* root, int level, int ltr)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        if(ltr)
        {
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else
        {
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct treenode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}










int main(){

 struct treenode* root = newnode(1);

 root->left = newnode(2);
 root->right = newnode(3);
 root->left->left = newnode(4);
 root->left->right = newnode(5);
 root->right->left = newnode(6);
 root->right->right = newnode(7);


 printspiral(root);

 return 0;
}
