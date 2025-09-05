#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
/*
Hôm nay, trận đấu đua xe công thức 1 đã được chuẩn bị sẵn n vị trí xuất phát a1,a2,...,an và có tổng cộng m tay đua tham gia. Người ta muốn sắp xếp các xe đua vào các vị trí sao cho khoảng cách nhỏ nhất giữa hai chiếc xe là lớn nhất.
Yêu cầu: Hãy tính toán và đưa ra giá trị lớn nhất này.
*/
/*
ý tưởng: Dùng binary search khoảng cách t thoả mãn có m chiếc xe có thể sắp xếp với khoảng cách >= t;
*/
bool check(int a[], int n, int m, int d)
{
    int cnt = 1; // luon chon vi tri dau tien
    int lastPos = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] - lastPos >= d) {
            cnt++;
            lastPos = a[i];
            if (cnt >= m)
                return true;
        }
    }
    return false;
}
int Bsearch(int a[], int n, int m)
{
    int l = 0; // khoang cach min nhat co the
    int r = a[n - 1] - a[0];
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(a, n, m, mid)) {
            ans = mid;
            l = mid + 1; // thu voi so lon hon
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    cout << Bsearch(a, n, m) << "\n";

    return 0;
}
