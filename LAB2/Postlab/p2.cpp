#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void reverse(int *ptr, int n) {
    int *start = ptr;
    int *end = ptr + n -1;
    while (start < end ){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() {
    
    return 0;
}