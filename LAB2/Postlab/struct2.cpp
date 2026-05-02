#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
SCP** sortDatabase(SCP** arr, int n) {
    if (arr == nullptr || n <= 1) return arr;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j]->id < arr[minIdx]->id) {
                minIdx = j;
            }
        }
        SCP* temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
    return arr;
}
int main() {
    
    return 0;
}