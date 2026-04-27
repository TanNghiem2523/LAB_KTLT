#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int diagonalProduct(int arr[][1000], int row, int col) {
    long long product = 1;
    int count = 0;
    for ( int i = 0; i<row;i++){
        product *= arr[i][count];
        count++;
    }
    return product;
}
int main() {
    
    return 0;
}