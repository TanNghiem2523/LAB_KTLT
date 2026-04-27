#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool isSpecialNumber(int n) {
    int count = 0;
    if ( n<2) return 0;
    
    else{
        int sum = 0;
        for ( int i = 2; i*i<=n;i++ ){
            if ( n%i==0) return 0;
        }
        while (n>0){
            sum+=n%10;
            n/=10;
        }
        if ( sum<2) return 0;
        for ( int i = 2; i*i<=sum;i++ ){
            if ( sum%i==0) return 0;
        }
    }
    return 1;
    
}
int main() {
    
    return 0;
}