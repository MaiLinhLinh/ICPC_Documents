// CLB Lập trình PTIT có một truyền thống vinh danh thành viên xuất sắc nhất mỗi tháng lên Fanpage của CLB. Dựa vào các hoạt động trong CLB hoặc thành tích mà cá nhân đạt được, CLB sẽ có cơ sở để xếp hạng các thành viên và chọn ra 3 người xứng đáng nhất.

// Biết rằng CLB Lập trình PTIT có N
//  thành viên, điểm ban đầu của mỗi người là 100
// . Trong suốt quá trình hoạt động, CLB đã đánh giá những khen thưởng và vi phạm và tổng hợp vào thông tin của mỗi thành viên thành một mảng số nguyên a
// :

// a[i]<0
// : điểm phạt
// a[i]>0
// : điểm thưởng
// Input
// Từ bàn phím nhập T
//  (1≤T≤10)
//  là số bộ test.

// Với mỗi bộ test nhập số nguyên dương N
//  (3≤N≤104)
//  là số lượng thành viên.

// Nhập vào thông tin của mỗi thành viên trong CLB:

// Tên
// Khóa (22 hoặc 23)
// M
// : kích thước mảng a
//  (0≤M≤50)
// Dòng tiếp theo chứa M
//  số nguyên (−106≤a[i]≤106,a[i]≠0)
//  là danh sách điểm của thành viên tương ứng
// Output
// Các bộ test cách nhau 1
//  dòng trống, với mỗi bộ test in ra thông tin 3
//  người có tổng điểm cao nhất bao gồm Tên và Khóa (cách nhau một dấu cách). Nếu điểm bằng nhau thì ưu tiên khóa dưới, cùng khóa thì sắp xếp tên theo thứ tự từ điển.
#include <bits/stdc++.h>
using namespace std;
struct thanhvien {
    string ten;
    int khoa;
    int tong;
    void nhaptt()
    {
        cin >> ten >> khoa;
    }
};
void inds(thanhvien s[])
{
    for (int i = 0; i < 3; i++)
        cout << s[i].ten << " " << s[i].khoa << "\n";
}
bool cmp(thanhvien a, thanhvien b)
{
    if (a.tong == b.tong) {
        if (a.khoa == b.khoa)
            return a.ten < b.ten;
        return a.khoa > b.khoa;
    }
    return a.tong > b.tong;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        thanhvien s[n];
        for (int i = 0; i < n; i++) {
            s[i].nhaptt();
            int m;
            cin >> m;
            int tmp = m;
            s[i].tong = 100;
            while (tmp--) {
                int diem;
                cin >> diem;
                s[i].tong += diem;
            }
        }
        sort(s, s + n, cmp);
        inds(s);
        cout << "\n";
    }
}