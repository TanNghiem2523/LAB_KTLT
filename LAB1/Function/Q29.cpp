#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool isPalindrome(const char* str) {
    int n = 0;
    while (str[n] !='\0'){
        n++;
    }
    string reverse ="";
    for ( int i=n-1;i>=0;i--){
        reverse+= str[i]; 
    }
    bool flag = 1;
    for ( int i = 0; i<n;i++){
        if (str[i] != reverse[i]){
            flag = 0;
            break;
        } 
    }
    return flag;
}
int main() {
    

    return 0;
}