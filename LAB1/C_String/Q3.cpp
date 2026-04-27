#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int find(char str[], char substr[]){
    int mom = strlen(str);
    int baby = strlen(substr);
    for ( int i = 0; i<=int(mom-baby);i++){
        for ( int j = 0; j<baby;j++){
            if(str[i+j] != substr[j]) break;
            if ((j + 1) == baby)
            {return i;}
        }
        
    }
    return -1;
}
int main() {
    char str[] = {"xin chao Viet Nam"};
    return 0;
}