#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
char* concatStr(char* str1, char* str2) {
    int len1 = 0;
    int len2 = 0;
    while (str1[len1] !='\0'){
        len1++;
    }
    while (str2[len2] !='\0'){
        len2++;
    }
    char *newStr= new char[len1+len2+1];
    for ( int i = 0;i<len1;i++){
        newStr[i] = str1[i];
    }
    for ( int i = 0;i<len2;i++){
        newStr[i+len1] = str2[i];
    }
    newStr[len1+len2] = '\0';
    return newStr;
}
int main() {
    
    return 0;
}