#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool isSymmetric(int arr[][1000], int row, int col) {
    for ( int i = 0 ; i<col;i++){
        for ( int j =0; j<col;j++){
            if ( arr[i][j] != arr[j][i]) return false;
    }
    }
    return true;
} 
int main() {
    
    return 0;
}