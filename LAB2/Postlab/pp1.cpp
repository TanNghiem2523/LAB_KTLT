#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    int **newMatrix = new int*[r];
    for ( int i = 0; i<r;i++){
        newMatrix[i] = new int[c+1];
    }
    for (int i = 0 ; i<r;i++){
        for ( int j = 0; j<col;j++){
            newMatrix[i][j] = matrix[i][j];
        }
    }
    for(int i = 0; i<r;i++){
        newMatrix[i][col] = colArr[i];
    }
    for (int i = 0 ; i<r;i++){
        for ( int j = col+1; j<c+1;j++){
            newMatrix[i][j] = matrix[i][j-1];
        }
        delete[]matrix[i];
    }
    delete[]matrix;
    matrix = newMatrix;
    return matrix;
}
int main() {
    
    return 0;
}