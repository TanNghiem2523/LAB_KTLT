#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<fstream>
using namespace std;
void process(string fileName){
    int max = 0;
    int num[50];
    int max = 0;
    ifstream file(fileName);
    if(file.is_open()){
        for( int i = 0;i<50;i++){
            file>>num[i];
        }
    }
    int MN = num[0]*num[1];
    for ( int i = 1;i<MN;i++){
        if (num[i]>max ) max = num[i];
    }
    for (int i = 1;i<num[0];i++){
        int maxRow = 0;
        for ( int j = 0;j<num[1];j++){
            if ( num[])
        }
    }
}
int main() {
    
    return 0;
}