#include <iostream>
#include <cstdio>

using namespace std;

void flip(int arr[], int n){

 int start =0, temp;

  if(start<n){
    temp = arr[start];
    arr[start] = arr[n];
    arr[n] = temp;
    start++;
    n--;
  }
}


int maximum_index(int arr[], int n){

 int mi, i;
 for(mi=0, i=0; i<n; i++)
  {
    if(arr[i]>arr[mi])
        mi = i;
  }
  return mi;
}


int pancakeSort(int* arr, int m){

  for(int current_size=m; current_size>1; current_size--){
    int mi = maximum_index(arr, current_size);

    if(mi!= current_size-1)
    {
       flip(arr, mi);

       flip(arr, current_size-1);
    }
  }


}



void printArray(int arr[], int m){

 for(int i=0; i<m; i++){
    cout<<arr[i]<<" ";
 }

}


int main(){

 int arr[] = {13, 10, 4, 5, 9, 20, 18};
 int m = sizeof(arr)/sizeof(arr[0]);

 pancakeSort(arr, m);

 cout<<"The sorted array ";
 printArray(arr, m);

 return 0;
}
