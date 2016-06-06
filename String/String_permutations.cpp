#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     cout<<" y "<<endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));

          cout<<a<<" y1 ";
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
          cout<<a<<" y2 ";
       }
   }
}

/* Driver program to test above functions */
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
