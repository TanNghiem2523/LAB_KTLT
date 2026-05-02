#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool deleteRow(int**& matrix, int r, int c, int row) {
    if (r<=0 || row >= r || r == 0 || matrix == nullptr || row < 0) return false;
    else if ( r == 1){
        delete[]matrix[row];
        delete matrix;
        matrix = nullptr;
        return true;
    }
    int **newptr = new int*[r-1];
    for ( int i = 0 ; i<r-1 ;i++){
        for (int j = 0; j<c;j++){
            newptr[i] = new int[c];
        }
    }
    for ( int i = 0; i<row; i++){
        for ( int j = 0 ; j<c ; j++){
            newptr[i][j] = matrix[i][j];
        } 
        delete[]matrix[i];
    }
    for ( int i = row + 1 ; i<r ; i++){
        for ( int j = 0 ; j<c; j++){
            newptr[i-1][j] = matrix[i][j];
        }
        delete[]matrix[i];
    }
    delete[]matrix;
    matrix = newptr;
    return true;
}
int main() {
    
    return 0;
}