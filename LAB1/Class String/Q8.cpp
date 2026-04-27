#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
void replaceString ( string s, string s1, string s2){
    int index = s.rfind(s1);
    if ( index != -1){
        s.replace(index,s1.length(),s2);
        cout<<s;
    }
    else{
        cout<<s;
    }
}
int main() {
    
    return 0;
}