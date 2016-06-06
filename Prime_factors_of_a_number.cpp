#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void prime_factors(int n){

 while(n%2==0){
    cout<<"2"<<" ";
    n = n/2;
 }
    for(int i=3; i<sqrt(n); i=i+2){

        while(n%i==0){
            cout<<i<<" ";
            n = n/i;
        }
    }

    if(n>2)
        cout<<n<<endl;


}


int main(){

 int n;

 cout<<"Enter the number whose factors you want to find: ";
 cin>>n;

 prime_factors(n);

 return 0;
 getchar();
}
