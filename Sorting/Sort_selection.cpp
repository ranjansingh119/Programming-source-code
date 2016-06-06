/*
 In each iteration of selection sort the current (i th ) element is considered
 smallest and compared with the rest of the remaining array.

 If an element smaller than the current smallest element is found then the smallest value is replaced
 with the current i th element.

 Selection Sort [Best/Worst: O(N^2)]

*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


void selection_sort(int arr[], int s){
 int temp =0;

 for(int i=0; i<s; i++){
    int smallest = i;
    for(int j = i+i; j<s; j++){

        if(arr[j]<arr[smallest])
            smallest = j;
    }

    temp = arr[smallest];
    arr[smallest] = arr[i];
    arr[i] = temp;
 }


}


int main(){

 int arr[] = {17, 7, 10, 1, 32, 29, 40, 38};
 int size = sizeof(arr)/sizeof(arr[0]);

 selection_sort(arr, size);

 for(int i=0;i<size; i++)
    cout<<arr[i]<<" ";


 return 0;
}
