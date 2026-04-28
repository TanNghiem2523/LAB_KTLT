#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int strlen (char *str){
    int count = 0;
    while (str[count] != '\0'){
        count++;
    }
    return (count);
}
char toLower(char c){
    if ( c>='A' && c<= 'Z') return c+32;
    return c;
}
void mostFrequentCharacter(char* str, char& res, int& freq) {
    char result = 'a';
    int n = strlen (str);
    int maxRepeat = 0;
    int start = 0;
    for ( int i = start; i< n;i++){
        int countRepeat = 0;
        char changeChar = toLower(str[i]);
        for ( int j = start;j<n;j++){
            if (changeChar == toLower(str[j])){
                countRepeat++;
            }}
            if (maxRepeat < countRepeat ) {
                maxRepeat = countRepeat;
                result = changeChar;
            }
            else if ( maxRepeat == countRepeat){
                if ( changeChar<result){
                    result = changeChar;
                }
            } 
}
freq = maxRepeat;
res = result;
}
int main() {
    return 0;
}