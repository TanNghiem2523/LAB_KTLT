#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void manage(string library_file, string book_file, string author_file) {
    // 1. Nhập tên thư viện L và tác giả A từ bàn phím
    string L, A;
    cin >> L >> A;

    int author_books[1000]; // Giả sử 1 tác giả viết tối đa 1000 cuốn sách
    int num_author_books = 0;
    bool author_found = false;

    // 2. Xử lý file author.txt (Tách chuỗi thủ công)
    ifstream af(author_file.c_str());
    if (af.is_open()) {
        string line;
        getline(af, line); // Bỏ qua dòng đầu tiên chứa số P
        
        while (getline(af, line)) {
            if (line.empty()) continue;
            
            string word = "";
            int word_count = 0;
            string current_author = "";
            
            // Duyệt từng ký tự để tự tách từ theo khoảng trắng
            for (int i = 0; i <= line.length(); ++i) {
                if (i == line.length() || line[i] == ' ' || line[i] == '\t' || line[i] == '\r') {
                    if (word != "") {
                        if (word_count == 0) {
                            current_author = word; // Từ đầu tiên là tên tác giả
                            if (current_author == A) author_found = true;
                        } else {
                            // Các từ sau là ID sách, chỉ lưu nếu đúng là tác giả A
                            if (current_author == A) {
                                int book_id = 0;
                                // Chuyển đổi chuỗi thành số nguyên
                                for (int j = 0; j < word.length(); ++j) {
                                    if (word[j] >= '0' && word[j] <= '9') {
                                        book_id = book_id * 10 + (word[j] - '0');
                                    }
                                }
                                author_books[num_author_books++] = book_id;
                            }
                        }
                        word = ""; // Reset từ để đọc từ tiếp theo
                        word_count++;
                    }
                } else {
                    word += line[i]; // Ghép từng ký tự vào từ
                }
            }
        }
        af.close();
    }

    // 3. Xử lý file library.txt
    int lib_books[5];
    bool lib_found = false;
    ifstream lf(library_file.c_str());
    if (lf.is_open()) {
        string N_str;
        lf >> N_str; // Đọc số N (bỏ qua)
        
        string lib_name;
        while (lf >> lib_name) {
            if (lib_name == L) {
                lib_found = true;
                for (int i = 0; i < 5; ++i) {
                    lf >> lib_books[i];
                }
                break; // Tìm thấy L thì không cần đọc tiếp các thư viện khác
            } else {
                int temp;
                for (int i = 0; i < 5; ++i) lf >> temp; // Bỏ qua 5 sách của thư viện không phải L
            }
        }
        lf.close();
    }

    // 4. Xử lý file book.txt (Chỉ đọc lướt qua để thỏa mãn yêu cầu đề)
    ifstream bf(book_file.c_str());
    if (bf.is_open()) {
        string M_str;
        bf >> M_str; // Đọc số M (bỏ qua)
        string b_id, year, category;
        // Đọc cho đến hết file
        while (bf >> b_id >> year >> category) {}
        bf.close();
    }

    // 5. Kiểm tra trùng khớp ID sách
    bool has_book = false;
    if (author_found && lib_found) {
        for (int i = 0; i < num_author_books; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (author_books[i] == lib_books[j]) {
                    has_book = true;
                    break;
                }
            }
            if (has_book) break;
        }
    }

    // 6. Xuất kết quả
    if (has_book) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
}