#include <iostream>
#include <string>
using namespace std;
int E1(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; 
}
string longestPalindrome(string s) {
    int start = 0;
    int max_len = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = E1(s, i, i);
        int len2 = E1(s, i, i + 1);
        int len = max(len1, len2);
        if (len > max_len) {
            max_len = len;
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, max_len);
}
int main() {
    string s;

    getline(cin, s);

    string result = longestPalindrome(s);
    cout << result << endl;

    return 0;
}