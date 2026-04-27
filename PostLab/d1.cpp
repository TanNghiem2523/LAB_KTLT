#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_Prime (int n){
    int count = 0;
    if (n<2) return 0;
    for ( int i = 2 ; i*i <=n;i++){
        if (n%i == 0) return 0;
    }
    return 1;   
}
int specialCells(int arr[][1000], int row, int col){
    int ccol[100];
    int rrow[100];
    int countRow = 0;
    int countCol = 0;
    int result = 0;
    for ( int i = 0; i < col;i++){
        int sumCol = 0;
        for ( int j = 0; j< row;j++){
            sumCol +=arr[j][i];
        }
    ccol[i] = {sumCol};
    }
    for ( int i = 0;i<col;i++){
        if (is_Prime(ccol[i])) countCol++;
    }
    for ( int i = 0; i<row;i++){
        int sumRow = 0;
        for ( int j = 0;j<col;j++){
            sumRow+=arr[i][j];
        }
    rrow[i] = {sumRow};
    }
    for ( int i = 0;i<row;i++){
        if (is_Prime(rrow[i])) countRow++;
    }
    result = countCol*countRow;
    return result;
}
int main() {
    
    return 0;
}