// Alee là một anh chàng thư sinh tài giỏi, anh ấy có CRUSH một bạn tên Layla. Dù thích Layla đã lâu nhưng mãi Alee vẫn chưa dám tỏ tình. Hôm nay anh ấy quyết định nhắn tin tỏ tình với CRUSH.

// Tuy nhiên một sự cố hi hữu đã xảy ra là bàn phím của Alee đã bị loạn phím.Các phím bị nhảy theo quy tắc sang phải hoặc sang trái tùy từng lúc, nếu không thể nhảy sang bên được nữa thì nó sẽ bị nhảy về kí tự ở đầu dòng (hoặc cuối dòng). Dòng tin tỏ tình đã chuyển thành dòng tin khác. Vì vậy Layla đã không hiểu Alee nhắn gì và không nhắn lại.

// Giờ Alee phải đi giải thích cho Layla hiểu. Bạn hãy giúp Alee dịch lại các mẩu tin nhắn nhé.

// Dưới đây là bàn phím qwerty chuẩn mà Alee đang dùng:

// qwertyuiop

// asdfghjkl;

// zxcvbnm,./

#include <bits/stdc++.h>
using namespace std;
string a[4] = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./" };
int x;
int check(char c)
{
    for (x = 0; x <= 2; x++) {
        for (int i = 0; i < a[x].size(); i++)
            if (c == a[x][i])
                return i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    char c;
    cin >> c;
    int k = 1;
    if (c == 'R')
        k = -1;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int pos = check(s[i]) + k;
        if (pos == a[x].size())
            pos = 0;
        else if (pos == -1)
            pos = a[x].size() - 1;
        cout << a[x][pos];
    }
}