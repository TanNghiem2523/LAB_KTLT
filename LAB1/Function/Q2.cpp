#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void sum2(int * array, int numEls, int &result)
{
    int sum = 0;
    for ( int i = 0; i<numEls;i++){
        sum+=array[i];
    }
    result = sum;
}
using namespace std;

int main() {
    
    return 0;
}