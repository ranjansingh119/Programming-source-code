#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int expand(string s, int i);

int expand(string s, int i){

 int c1, max_s= 0;

 int c = c1=1;
 int size_s = s.length();
 cout<<"length of string passed "<<" "<<s<<" "<<size_s<<endl;

  if((i-1)==0 || ((i-1)%2!=0))
    return c1;

 else if(((i-1)%2==0) && (size_s%2!=0)){

    int j=size_s/2;
        for(int k=1;k<=j;k++){
            if(s[j-k] == s[j+k])
              {
                c1 +=2;
              }

              if(c>c1)

        }

       return max_s;
    }
 }


int main(){
string s = "1232179898";
int max_len;
string st;



for(int m=1; m<=s.length(); m++){
    st = s.substr(0, m);

    max_len = expand(st, m);
}
cout<<max_len;

return 0;
getchar();
}


