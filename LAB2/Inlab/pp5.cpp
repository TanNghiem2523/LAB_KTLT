#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int** transposeMatrix(int** matrix, int r, int c) {
    if ( r == 0 && c == 0) return NULL;
    int **newMatrix = new int*[c];
    for ( int i = 0; i<c;i++){
        newMatrix[i] = new int[r];
    }
    for ( int i = 0;i<c;i++){
        for ( int j = 0;j<r;j++){
            newMatrix[i][j] = matrix[j][i];
        }
    }
    return newMatrix;
}
int main() {
    
    return 0;
}