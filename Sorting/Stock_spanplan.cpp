#include <iostream>
#include <cstdio>
#include <stack>


using namespace std;


void stock_plan(int price[], int stock_span[], int s){

 stack<int> st1;
 st1.push(0);

 stock_span[0] = 1;

 for(int i=1; i<s; i++){

  while(!st1.empty() && (price[i]>=price[st1.top()])){
    st1.pop();
  }

  stock_span[i] = (st1.empty()) ? (i+1): (i-st1.top());

  st1.push(i);
 }

}


void print_stockArray(int stock_span[], int s){

 for(int i=0; i<s; i++){
    cout<<stock_span[i]<< " ";
 }
}

int main(){
int price[] = {100, 80, 60, 70, 60, 75, 85};
int s = sizeof(price)/sizeof(price[0]);
int stock_span[s];


stock_plan(price, stock_span, s);

print_stockArray(stock_span, s);

return 0;
getchar();

}
