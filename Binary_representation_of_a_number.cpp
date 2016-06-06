#include <iostream>
#include <cstdio>

using namespace std;

void binary_conversion(int num);

void binary_conversion(int num){

 if(num>1){
    binary_conversion(num/2);
 }

  cout<<(num%2);
}


int main(){

 int n;
 cout<<"Enter the number whose binary representation you want: ";
 cin>>n;

 binary_conversion(n);

 return 0;
 getchar();
}
