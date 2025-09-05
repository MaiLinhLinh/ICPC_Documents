// Kì thi cuối kì 1 của các bạn D21 đã kết thúc.Các bạn D21 ProPTIT đã có điểm tất cả 3 môn học lần lượt Toán, Lí và C++. Tuy nhiên, bảng điểm các bạn D21 nhận được chưa được sắp xếp, các bạn hãy giúp các bạn D21 sắp sếp lại bảng điểm theo tổng số điểm giảm dần nhé (Nếu tổng điểm bằng nhau sẽ sắp sếp theo tên theo thứ tự từ điển).

// Input
// Dòng đầu tiên là số lượng sinh viên n
//  (1≤n≤100)
// .

// n
//  dòng sau mỗi dòng là tên sinh viên thứ i
//  (1≤Length≤100)
// .

// n
//  dòng tiếp theo, mỗi dòng lần lượt là điểm môn Toán, Lí, C++ của sinh viên thứ i
//  (Điểm các môn thỏa mãn không âm và bé hơn hoặc bằng 10)

// Điểm là số nguyên.

// Output
// Bảng điểm đã được sắp xếp theo tổng số điểm giảm dần.
#include <bits/stdc++.h>
using namespace std;
int n;
struct sinhvien {
    string ten;
    int t, l, c;
    int tong;
    void nhapten()
    {
        getline(cin, ten);
    }
    void nhapdiem()
    {
        cin >> t >> l >> c;
    }
};
void inds(sinhvien s[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << s[i].ten << " " << s[i].t << " " << s[i].l << " " << s[i].c << "\n";
    }
}
bool cmp(sinhvien a, sinhvien b)
{
    if (a.tong == b.tong)
        return a.ten < b.ten;
    else
        return a.tong > b.tong;
}
int main()
{
    int n;
    cin >> n;
    getchar();
    sinhvien s[100];
    for (int i = 0; i < n; i++)
        s[i].nhapten();
    for (int i = 0; i < n; i++)
        s[i].nhapdiem();
    for (int i = 0; i < n; i++)
        s[i].tong = s[i].t + s[i].l + s[i].c;
    sort(s, s + n, cmp);
    inds(s, n);
    return 0;
}