#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 int recursiveSum(int arr[], int size) {
    if (size<1) return 0; 
    return (arr[size-1]+recursiveSum(arr,size-1)); 
    
}
using namespace std;

int main() {
   
    return 0;
}