#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


struct node{

 int data;
  struct node* next;
};


void insert_node(struct node** head, int data){

 struct node* temp = (struct node* )malloc(sizeof(struct node));
 temp->data = data;
 temp->next = (*head);
 (*head) = temp;

}


void reverse_list(struct node** head){
struct node* current = *head;
struct node* prev = NULL;
struct node* next = NULL;

while(current!=NULL){
    next = current->next;
    current->next= prev;
    prev= current;
    current = next;

}

(*head) = prev;
}


bool compare(struct node* t1, struct node* t2){
 struct node* h1 = t1;
 struct node* h2 = t2;

 while(h1 && h2){
  if(h1->data == h2->data){
    h1 = h1->next;
    h2 = h2->next;
   }
    else return 0;
    }


    if (h1 == NULL && h2 == NULL)
        return 1;

    /* Will reach here when one is NULL
      and other is not */
    return 0;
}


bool palindrome(struct node* head){

 struct node* first = head;
 struct node* rest = head;
 struct node* prev_of_rest = head;
 struct node* middle_node = NULL;
 struct node* second_half = NULL;
 bool result = true;


 if(head!= NULL   &&  head->next!=NULL){
    while(first!= NULL && first->next!= NULL)
    {
      first = first->next->next;
      prev_of_rest = rest;
      rest = rest->next;
    }

    if(first!= NULL)
    {
        middle_node = rest;
        rest = rest->next;
    }

    second_half = rest;
    prev_of_rest->next = NULL;
    reverse_list(&second_half);
    result = compare(head, second_half);

    reverse_list(&second_half);

    if(middle_node!=NULL){
        prev_of_rest->next = middle_node;
        middle_node->next = second_half;
    }

    else prev_of_rest->next = second_half;
 }

 return result;
}



void printlist(struct node* node){

  while(node!=NULL){

    cout<<node->data;
    node = node->next;
  }

}




int main(){

struct node* head = NULL;

insert_node(&head, 1);
insert_node(&head, 2);
insert_node(&head, 3);
insert_node(&head, 2);
insert_node(&head, 1);


printlist(head);
cout<<"\n";
palindrome(head)? cout<<"given string is palindrome": cout<<"given string is not palindrome";

return 0;
getchar();
}
