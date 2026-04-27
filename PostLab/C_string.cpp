#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
void process(const char *name, char *outstr) {
    int i = 0;
    int j = 0;
    bool newWord = 1;
    while(name[i] != '\0'){
        char temp = name[i];
        if ((temp >='a' && temp<='z')||(temp >='A' && temp<='Z')){
            if (newWord){
                if (j>0){
                    outstr[j] = ' ';
                    j++;
                }
                if (temp >='a' && temp<='z') {
                outstr[j] = temp - 32;
            }
            else{
                outstr[j] = temp;
            }
            newWord = 0;
            }
            else {
                if (temp >='A' && temp<='Z')
                    {outstr[j] = temp + 32;}
                else outstr[j] = temp;
            }
            j++;
        }
        else if ( temp == ' '){
                newWord = 1;
        }
                i++;
    }
    outstr[j] = '\0';
}
int main() {
    
    return 0;
}