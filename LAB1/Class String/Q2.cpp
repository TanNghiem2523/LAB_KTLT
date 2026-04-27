#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
void findAllIndex(string s1, string s2){
    bool regFlag = false;
    int found = 0;
    while ( (found = s1.find(s2[0],found)) != -1){
        cout << found <<" ";
        regFlag = 1;
        found++;
    }
    if ( regFlag == 0){
        cout << "-1";
    }
}
int main() {
    
    return 0;
}