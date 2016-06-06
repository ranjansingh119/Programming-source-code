#include <iostream>
#include <cstdlib>
#include <cstdio>


using namespace std;


typedef struct Queue{

 int capacity;
 int* array;
 int front;
 int rear;

}Queue;


Queue* create_queue(int capacity){

 Queue* queue = (Queue* )malloc(sizeof(Queue));
 queue->capacity = capacity;
 queue->front = queue->rear= -1;
 queue->array = (int*)malloc(sizeof(queue->capacity * sizeof(int)));

 return queue;
}

int isempty(Queue* queue){
    return queue->front = -1;
}


void Enqueue(Queue* queue, int item){

 queue->array[queue->rear++] = item;
 if(isempty(queue))
    queue->front++;

}


int Dequeue(Queue* queue){
 int item = queue->array[queue->front];

 if(queue->front == queue->rear)
    queue->front = queue->rear = -1;

  else
    queue->front++;
  return item;

}





int compare_ascending(const void* a, const void* b){

 return *(int*)a > *(int*)b;
}


int compare_descending(const void* a, const void* b){

 return *(int*)a < *(int*)b;
}


void printArr (int* arr, int size)
{
    int i;
    for (i = 0; i< size; ++i)
        cout<<arr[i]<<" ";
}


void accomodate_all_three(int* arr, Queue* queue0, Queue* queue1, Queue* queue2, int* top){

 while(!isempty(queue0))
    arr[(*top)++] = Dequeue(queue0);

 while(!isempty(queue1))
    arr[(*top)++] = Dequeue(queue1);

 while(!isempty(queue2))
    arr[(*top)++] = Dequeue(queue2);

}


int largest_multiple_of_3(int *arr, int s){

 int sum =0, i;

 qsort(arr, s, sizeof(int), compare_ascending);               //just modifies the given array and arranges them in ascending order

  Queue* queue0 = create_queue(s);
  Queue* queue1 = create_queue(s);
  Queue* queue2 = create_queue(s);

  // 3 queues have been created.

  for(i=0,sum=0; i<s; i++){
     sum = sum+arr[i] ;

     if(arr[i]%3==0)
       Enqueue(queue0, arr[i]);

       else if(arr[i]%3==1)
       Enqueue(queue1, arr[i]);

         else
         Enqueue(queue2, arr[i]);

  }


    if(sum%3==1){

       if(!isempty(queue1))
            Dequeue(queue1);

        else{
            if(!isempty(queue2))
            Dequeue(queue2);

             else
               return 0;

                if(!isempty(queue2))
                  Dequeue(queue2);

                  else
                   return 0;
        }
     }

      else if(sum%3==2){
           if(!isempty(queue2))
            Dequeue(queue2);

             else{
                if(!isempty(queue1))
                 Dequeue(queue1);

             else
               return 0;

                if(!isempty(queue1))
                  Dequeue(queue1);

                  else
                   return 0;

             }

      }


   int aux_array[s], top=0;

   accomodate_all_three(aux_array, queue0, queue1, queue2, &top);

   qsort(aux_array, top, sizeof(int), compare_descending);

   printArr (aux_array, top);

   return top;

}


int main(){

 int arr[] = {8, 7, 1, 6, 0, 15};
 int s = sizeof(arr)/sizeof(arr[0]);

 if(largest_multiple_of_3(arr, s)==0)
    cout<<"not possible";


 return 0;
 getchar();
}
