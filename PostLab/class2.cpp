#include <iostream>
#include <string>

using namespace std;

int longestNonRepeatSubString(string s) {
    // Mảng lưu vị trí cuối cùng xuất hiện của 256 ký tự ASCII
    int lastIndex[256];
    
    // Khởi tạo tất cả bằng -1 (nghĩa là chưa ký tự nào xuất hiện)
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int left = 0; // Cạnh trái của "cửa sổ trượt"

    for (int right = 0; right < (int)s.length(); right++) {
        // Ép kiểu sang unsigned char để tránh lỗi với các ký tự đặc biệt (ASCII > 127)
        unsigned char c = s[right];

        // Nếu ký tự này đã xuất hiện và vị trí cũ của nó nằm trong cửa sổ hiện tại
        if (lastIndex[c] >= left) {
            // Nhảy cạnh trái đến ngay sau vị trí cũ của ký tự đó
            left = lastIndex[c] + 1;
        }

        // Cập nhật vị trí mới nhất của ký tự vừa đọc
        lastIndex[c] = right;

        // Tính độ dài cửa sổ hiện tại (right - left + 1) và cập nhật max
        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main()  {
    string s;
    // Lưu ý: cin >> s sẽ dừng lại khi gặp khoảng trắng. 
    // Nếu đề bài yêu cầu đọc cả chuỗi có dấu cách, bạn nên dùng getline(cin, s);
    if (!(cin >> s)) return 0; 
    
    cout << longestNonRepeatSubString(s);
    return 0;
}