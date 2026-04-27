#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
void printFirstRepeatedWord(char str[]){
    int max =31;
    int count=0;
    int index = 0;
    bool flag = 0;
    char cutWord[100][max];
    for ( int i= 0; i<=strlen(str);i++){
        if (str[i] == ' ' || str[i]=='\0') {
            cutWord[count][index] ='\0';
            count ++;
            index=0;
            continue;
        }
        cutWord[count][index] = str[i];
        index++;
    }
    for ( int i = 0; i<count;i++){
        for ( int j = 0; j<i;j++){
            if ((strcmp(cutWord[i],cutWord[j])) == 0){
                cout <<cutWord[i];
                flag = 1;
                break;
        }
        if (flag) break;    
    }}
if ( !flag){
    cout<<"No Repetition";
}
}
int main() {
    return 0;
}