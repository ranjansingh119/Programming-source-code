#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


struct Listnode{

 int data;
 struct Listnode* next;
};

struct MinheapNode{

 Listnode* head;
};

struct Minheap{                       /*
                                                 array[0] -> 30->40->NULL
                                                 /    \
                                                /      \
                           array[1]->35->45->NULL      array[2]->10->60-.70->86->100->NULL
                                       */
int count;
int capacity;
MinheapNode* array;

};



Minheap* create_minheap(int capacity){

 Minheap* minheap = new Minheap;
 minheap->capacity = capacity;
 minheap->count =0;
 minheap->array = new MinheapNode[minheap->capacity];

 return minheap;
}


void insert(struct Listnode** head, int data){

 struct Listnode* n = new Listnode;
 n->data = data;
 n->next = (*head);
 (*head) = n;

}


void swap (MinheapNode* a, MinheapNode* b){

 MinheapNode temp = *a;
 *a = *b;
 *b = temp;
}


void minHeapify(Minheap* minHeap, int index){

 int left, right, smallest;

 smallest = index;
 left = 2* index+1;
 right = 2* index+2;

 if(left<minHeap->count && ((minHeap->array[left].head->data) < (minHeap->array[smallest].head->data)) )
    smallest = left;

   if(right<minHeap->count && ((minHeap->array[right].head->data) < (minHeap->array[smallest].head->data)) )
    smallest = right;

 if(smallest != index)
 {
   swap(&minHeap->array[smallest], & minHeap->array[index]);
   minHeapify(minHeap, smallest);
 }
}


void build_minheap(Minheap* minHeap){

 int i, m;
 m = minHeap->count-1;
 for(i= (m-1)/2; i>=0; --i){
    minHeapify(minHeap, i);
 }
}


void populate_heap(Minheap* minHeap, Listnode* *array, int siz){

 for(int i=0;i<siz;i++){
    minHeap->array[minHeap->count++].head = array[i];
 }
 build_minheap(minHeap);
}


int isempty( Minheap* minHeap )
{
    return (minHeap->count == 0);
}


Listnode* extractMin( Minheap* minHeap )
{
    if( isempty( minHeap ) )
         return NULL;

    // The root of heap will have minimum value
    MinheapNode temp = minHeap->array[0];

    // Replace root either with next node of the same list.
    if( temp.head->next )
        minHeap->array[0].head = temp.head->next;
    else // If list empty, then reduce heap size
    {
        minHeap->array[0] = minHeap->array[ minHeap->count - 1 ];
        --minHeap->count;
    }

    minHeapify( minHeap, 0 );
    return temp.head;
}



void external_arraysort(Listnode* array[], int s){

Minheap* minHeap = create_minheap(s);

populate_heap(minHeap, array, s);

 while ( !isempty( minHeap ) )
    {
        Listnode* temp = extractMin( minHeap );
        printf( "%d ",temp->data );
    }
}



int main(){

 int size=3;

 Listnode* array[size];

 array[0] = NULL;
 insert(&array[0], 50);
 insert(&array[0], 40);
 insert(&array[0], 30);


 array[1] = NULL;
 insert(&array[1], 45);
 insert(&array[1], 35);


 array[2] = NULL;
 insert(&array[2], 100);
 insert(&array[2], 86);
 insert(&array[2], 70);
 insert(&array[2], 60);
 insert(&array[2], 10);


 external_arraysort(array, size);
 return 0;
}

