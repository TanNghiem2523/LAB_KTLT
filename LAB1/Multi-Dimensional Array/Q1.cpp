#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int findMaxColumn(int arr[][1000], int row, int col) {
    if ( col<=0 ||row <= 0) return 0;
    long long max = 0;
    for ( int i = 0 ; i<row;i++){
        max += arr[i][0];
    }
    int index = 0;
    for (int i = 0; i<col;i++){
        long long sum = 0;
        for ( int j =0; j<row;j++){
            sum += arr[j][i];
        }
        if ( sum >= max){
                index = i;
                max = sum;
            }
    }
    return index;
}
int main() {
    
    return 0;
}