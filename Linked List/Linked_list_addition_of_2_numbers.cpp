#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node{

int data;
struct node* next;
};

struct node* summation(struct node* first, struct node* second);
struct node* newnode(int data);
void list_insert(struct node** head, int data);
void printlist(struct node* n);
void reverse_list(struct node** head);

struct node* summation(struct node* first, struct node* second){

 struct node* result= NULL;
 int carry=0, sum = 0;
 struct node* prev = NULL;
struct node* temp = NULL;

 while(first!=NULL || second!=NULL){

    sum =  ((first!=NULL)? first->data : 0) + ((second!=NULL)? second->data : 0) + carry;

    carry = (sum>=10)? 1 : 0;

    sum = sum %10;

    temp = newnode(sum);

    if(result==NULL){
        result = temp;
    }
    else{
        prev->next = temp;
    }

    prev = temp;

    if(first!=NULL)
     first =  first->next;

     if(second!=NULL)
      second =  second->next;
 }

  if(carry>0){
    temp->next = newnode(carry);

  }

 return result;
}


void reverse_list(struct node** head){

 struct node* current = *head;
 struct node* prev = NULL;
 struct node* next = NULL;

 while(current!=NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;

 }
 (*head) = prev;
}



struct node* newnode(int data){

 struct node* t = (struct node* )malloc(sizeof(struct node));
 t->data = data;
 t->next = NULL;
 return (t);
}


void list_insert(struct node** head, int data){

 struct node* temp = newnode(data);
 temp->next = (*head);
 (*head) = temp;

}


void printlist(struct node* n){

 while(n!=NULL){
    cout<<n->data<<" ";
    n = n->next;
 }
}

int main(){

struct node* first = NULL;
struct node* second = NULL;
struct node* head = NULL;

list_insert(&first, 8);
list_insert(&first, 6);
list_insert(&first, 9);

printlist(first);
cout<<endl;
reverse_list(&first);


list_insert(&second, 7);
list_insert(&second, 4);
list_insert(&second, 9);
list_insert(&second, 7);
list_insert(&second, 9);

printlist(second);
cout<<endl;

reverse_list(&second);

head = summation(first, second);

reverse_list(&head);
printlist(head);

return 0;
getchar();
}

