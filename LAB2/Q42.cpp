#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int getValueAtIndex(int *ptr,int k){
    return ptr[k];
}
int main() {
    int a[4] = {1,2,3,4};
    int *ptr = a;
    cout<<getValueAtIndex(ptr,2);
    return 0;
}