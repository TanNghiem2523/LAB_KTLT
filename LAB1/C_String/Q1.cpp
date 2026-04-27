#include <iostream>
#include <vector>
#include <string>
#include<cstring>
#include <algorithm>

using namespace std;
void reverse(char str[]){
    int n= strlen( str );
    for (int i = 0;i<n/2;i++){
        char a = str[n-i-1];
        str[n-i-1]=str[i];
        str[i] =a;
    }
}
int main() {
    
    return 0;
}