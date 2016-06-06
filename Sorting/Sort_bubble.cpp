/*In each iteration of bubble sort the largest element in the current
iteration will be shifted to the right end or below

  Bubble Sort [Best: O(n), Worst:O(N^2)]

*/


#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void bubble_sort(int arr[], int s){

 int t=0;

 for(int i=0;i<s; i++){

    for(int j=0; j<s-i-1; j++){

        if(arr[j]>arr[j+1])
        {
          t = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = t;
        }
    }
 }


}



int main(){

int arr[] = {17, 7, 10, 1, 32, 29, 40, 38};
int size = sizeof(arr)/sizeof(arr[0]);

bubble_sort(arr, size);

for(int i=0;i<size; i++){

 cout<<arr[i]<<" ";

}

return 0;
}
