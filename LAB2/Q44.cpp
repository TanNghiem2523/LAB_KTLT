#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int calcSum ( int *ptr, int n){
    int sum = 0;
    for ( int i=0 ; i<n;i++){
        sum+=*(ptr + i);
    }
    return sum;
}
int main() {
    
    return 0;
}