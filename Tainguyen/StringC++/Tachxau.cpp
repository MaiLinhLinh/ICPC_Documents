// Cho xâu ký tự S bao gồm các ký tự 'A',..,'Z' và các chữ số '0',...,'9'.

// Yêu cầu: In các ký tự từ 'A',.., 'Z' trong S theo thứ tự alphabet và nối với tổng các số có trong S ở cuối cùng. Ví dụ S = "ACCBA10D2EW30" ta nhận được kết quả: "AABCCDEW42".

// Lưu ý: Các số có trong chuỗi không vượt quá 1018
#include <bits/stdc++.h>
using namespace std;
void sapxep(string s)
{
    string chu;
    long long sum = 0, tong = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            sum = sum * 10 + s[i] - '0';
        else if (isalpha(s[i])) {
            chu += s[i];
            tong += sum;
            sum = 0;
        }
    }
    tong += sum;
    sort(chu.begin(), chu.end());
    cout << chu << tong << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        sapxep(s);
    }
    return 0;
}