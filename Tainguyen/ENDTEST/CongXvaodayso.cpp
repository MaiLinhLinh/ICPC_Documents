// Tí được thầy giáo ở lớp giao cho 1 dãy số không âm: a1,a2,...an
//  và yêu cầu sau:

// Hãy chọn số nguyên x
//  bất kì và cộng x
//  vào một số phần tử của mảng (có thể không cộng vào phần tử nào). Tiếp theo, trừ x
//  vào một số phần tử khác của mảng (có thể không trừ vào phần tử nào). Và thầy giáo muốn sau khi thực hiện các thao tác trên sẽ thu được 1 mảng gồm các phần tử bằng nhau.

// Bạn hãy giúp Tí xác định xem có tồn tại số x
//  thỏa mãn yêu cầu bài toán không nhé!
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int num = (a[n - 1] + a[0]) / 2;
    int x = num - a[0];
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != num && a[i] + x != num && a[i] - x != num) {
            cout << "NO\n";
            res = 1;
            break;
        }
    }
    if (res == 0)
        cout << "YES\n";
}