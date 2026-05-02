#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool palindromeRecursion(string s)
{
    if (s.length() <= 1) return true;
    if (s[0] != s[s.length() - 1]) return false;
    return palindromeRecursion(s.substr(1, s.length() - 2));
}

int main()
{
    string s;
    while (getline(cin, s) && s[0] != '*') {
        if (/*palindrome( s) &&*/ palindromeRecursion(s)) cout<<"true"<<" "<<"true"<<endl;
        else cout<<"false"<<" "<<"false"<<endl;
    }
    return 0;
}