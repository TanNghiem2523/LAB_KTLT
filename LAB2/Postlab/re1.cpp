#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int findOccurrences(int nums[], int size, int element) {
    int count = 0;
    if (size < 0) return 0;
    if (nums[size] == element ) count++;
    return count + findOccurrences(nums,size-1,element);
}
int main() {
    
    return 0;
}