#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int convertToBaseM(int n, int m = 2) {
    if (n == 0) return 0;
    
    int result = 0;
    int multiplier = 1;
    
    while (n > 0) {
        int remainder = n % m;
        result += remainder * multiplier;
        n /= m;
        multiplier *= 10;
    }
    
    return result;
}
int main() {
    
    return 0;
}