#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool checkOdd (int n){
    if (n < 1) return 0;
    if (n%2 != 0) return 1;
    else return 0;
}
int subMatrix(int arr[][1000], int row, int col){
    int count=0;
    for ( int i = 0; i<row-1;i++){
        for ( int j = 0; j<col-1;j++){
            int sum = (arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1]);
            if(checkOdd(sum)) count++;
        }
        
    }
    return count;
}
int main() {
    
    return 0;
}