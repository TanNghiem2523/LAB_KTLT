#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
void process(const char str[], char outstr[]){
    int i = 0; int j = 0;
    while ( str[i]!='\0' ){
        if ( str[i]!=' '){
            outstr[j] = str[i];
            i++;
            j++;
        }
        else{
            while (str[i]==' ')
            {
                i++;
            } 
            if ( j>0 && str[i]!='\0'){
            outstr[j] = ' ';
            j++;
        }           
        }
    }
outstr[j] = '\0';
}
int main() {
    
    return 0;
}