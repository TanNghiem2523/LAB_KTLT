#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
void recover(char signal[]) {
    int n = strlen(signal);
    for (int i = 0;i<n;i++){
        if ((signal[i]) == 32) continue;
        else if ( signal[i]>= 97 &&  signal[i]<=122){
            signal[i]-=32;
        }
         else if (signal[i]>= 65 &&  signal[i]<=90){
            signal[i]+=32;
        }
}}
int main() {
    
    return 0;
}