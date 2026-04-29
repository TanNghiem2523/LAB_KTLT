#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int** readArray()
{
    int number;
   int **a = new int*[10];
   for ( int i = 0 ;i<10;i++){
       a[i] = new int[10];
   }
   for ( int i = 0;i<10;i++){
       bool endRow = 0;
       for ( int j = 0;j<10;j++){
           if (!endRow){
               cin>>number;
               if(number != 0){
                   a[i][j] = number;
               }
               else {
                   for ( int k = j;k<10;k++){
                       a[i][k] = 0;
                   }
                   endRow = 1;
               }
           }
           else if (endRow) break;
       }
   }
   return a;
}
int main() {
    
    return 0;
}