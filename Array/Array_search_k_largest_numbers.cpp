#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


void find_largest(int arr[], int num, int s){

int temp, largest;


    for(int i=0;i<num;i++){

        largest = i;
        for(int j=i; j<s; j++){

            if(arr[largest]<arr[j]){
                largest = j;
            }
        }

        if(largest != i)
        {
           temp = arr[largest];
           arr[largest] = arr[i];
           arr[i] = temp;
        }

     cout<<arr[i]<<" ";
    }

}



int main(){

int k=3;

int arr[] = {1, 23, 12, 9, 30, 2, 50};
int size = sizeof(arr)/sizeof(arr[0]);

find_largest(arr, k, size);


 return 0;
}

