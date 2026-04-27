#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
void uppercase(string output){
    string content;
    getline (cin,content);
    for ( int i = 0; i<content.length();i++){
        if (content[i] >='a' && content[i] <='z'){
            content[i] -=' ';
        }
    }
    ofstream file(output);
    if ( file.is_open()){
    file<<content;
    file.close();
}
}
int main() {
    
    return 0;
}