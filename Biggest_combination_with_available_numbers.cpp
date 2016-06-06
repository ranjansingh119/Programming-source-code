#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int compare_numbers(string X, string Y){

  string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;


}

void printlargest_number(vector<string> arr){

sort(arr.begin(), arr.end(), compare_numbers);

for(int i=0; i<arr.size(); i++){
    cout<<arr[i];
}

}


int main(){

vector<string> arr;

arr.push_back("28");
arr.push_back("542");
arr.push_back("45");
arr.push_back("87");
arr.push_back("39");

printlargest_number(arr);

return 0;
getchar();
}
