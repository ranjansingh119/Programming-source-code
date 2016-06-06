#include <iostream>
#include <cstdio>

using namespace std;


void next_greater_element(int arr[], int s){

 int largest;
 int count[s];
 for(int i=0; i<s;i++){

  largest = i;
  count[i] = 0;

   for(int j=i+1; j<s; j++ )
   {
       if(arr[j]>arr[largest]){
        largest = j;
        count[i]++;

        if(count[i] == 1)
           goto FINISH;
       }
   }

   FINISH: if(largest != i && count[i]==1)
             cout<<arr[i]<<"-->"<<arr[largest]<<endl;
               else
                 cout<<arr[i]<<"-->"<<"-1"<<endl;
 }


}


int main(){

 int arr[]  = {13, 6, 7, 12};
 int size = sizeof(arr)/sizeof(arr[0]);

 next_greater_element(arr, size);

 return 0;
}
