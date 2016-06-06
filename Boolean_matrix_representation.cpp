/*conversion from normal matrix into boolean matrix*/

#include <iostream>
#include <cstdio>
#define n 3
#define m 3

using namespace std;

void convert_matrix(bool arr[n][m]){

 bool r[n];
 bool c[m];
 int i, j;

 for(i=0; i<n; i++){
    r[i] =0;
 }

 for(j=0; j<m; j++){
    c[j] =0;
 }

 for(i=0; i<n; i++){

    for(j=0; j<m; j++){
        if(arr[i][j] == 1){
            r[i] =1;
            c[j] =1;
        }
    }
 }


 for(i=0; i<n; i++){

    for(j=0; j<m; j++){
        if((r[i] == 1) || (c[j]==1)){
            arr[i][j] = 1;
        }
    }
 }

}


void print_matrix(bool arr[n][m]){

 int i, j;

 for(i=0; i<n; i++){
    for(j=0; j<m; j++){
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
 }

}


int main(){

bool arr[n][m] = {{1, 0, 1},
   {1, 0, 0},
   {0, 1, 0}};

 cout<<"The normal matrix:"<<endl;
 print_matrix(arr);

 convert_matrix(arr);
 cout<<"The converted matrix: "<<endl;

 print_matrix(arr);

 return 0;
 getchar();

}
