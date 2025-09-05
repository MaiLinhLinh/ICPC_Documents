// Dòng họ nhà H có rất nhiều người. Mỗi dịp tết đến xuân về H muốn đi chúc tết theo thứ tự từ các cụ lớn tuổi nhất trước. (Nếu 2 người bằng tuổi H sẽ đi chúc người có tên theo thứ tự từ điển nhỏ hơn).

// Nhưng do quá nhiều nên H không thể nhớ hết được. Mọi người hãy giúp H nhé.

// Input
// Dòng đầu tiên là một số nguyên n
//  là số người mà H phải đi chúc tết năm nay. (n≤100)
// . Tiếp theo có n
//  cặp dòng.

// - Dòng 1 gồm xâu không vượt quá 10000 kí tự là tên của người.

// - Dòng 2 là tuổi của người đó.

// Output
// In ra danh sách đã được sắp xếp theo yêu cầu đề bài.
#include <bits/stdc++.h>
using namespace std;
struct dongho {
    string ten;
    int tuoi;
    void nhap()
    {
        cin.ignore();
        getline(cin, ten);
        cin >> tuoi;
    }
};
void inds(dongho s[], int n)
{
    for (int i = 0; i < n; i++)
        cout << s[i].ten << "\n";
}
bool cmp(dongho a, dongho b)
{
    if (a.tuoi == b.tuoi)
        return a.ten < b.ten;
    else
        return a.tuoi > b.tuoi;
}
int main()
{
    int n;
    cin >> n;
    dongho s[101];
    for (int i = 0; i < n; i++)
        s[i].nhap();
    sort(s, s + n, cmp);
    inds(s, n);
    return 0;
}