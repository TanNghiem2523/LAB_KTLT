#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int chinh = 0;
    int phu = 0;
    for ( int i = 0;i<row;i++){
        for ( int j = 0; j<col;j++){
            if ( (x+y) == (i+j)) {
              chinh+=arr[i][j];
            }
            if ( (x-y) == (i-j)) {
              phu+=arr[i][j];
            }
        }
    }
    return abs(-chinh + phu);
}
int main() {
    
    return 0;
}