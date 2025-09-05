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
// dem so luong doan con co hieu gia tri lon nhat va gia tri nho nhat khong qua mot so k cho truoc
// y tuong tuong tu bai doan con tinh tien max, min
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    deque<int> min_dq, max_dq;
    // min_dq voi min_dq.front() la min cua doan tu l den r, max_dq.front() la max doan tu l den r
    ll ans = 0;
    int l = 1;
    // tang chi so r len lan luot
    for (int r = 1; r <= n; r++) {
        // voi moi r, cap nhat min max trong doan den r
        while (!min_dq.empty() && a[min_dq.back()] >= a[r])
            min_dq.pop_back();
        min_dq.push_back(r);

        while (!max_dq.empty() && a[max_dq.back()] <= a[r])
            max_dq.pop_back();
        max_dq.push_back(r);

        // loai bo cac doan không thoả mãn yêu cầu
        while (!min_dq.empty() && !max_dq.empty() && a[max_dq.front()] - a[min_dq.front()] > k) {
            // thì tức là l không còn thoả mãn, nên mình tăng l lên để thu hẹp đoạn để max - min có thể <= k.
            l++;

            // khi đó, trong 2 deque sẽ không còn giá trị của index l - 1 nữa vì mình đã tăng lên rồi, nên phải xoá đi
            if (min_dq.front() == l - 1)
                min_dq.pop_front();
            if (max_dq.front() == l - 1)
                max_dq.pop_front();
        }
        // đoạn thoả mãn từ l đến r. => tổng số đoạn là r - l + 1
        ans += r - l + 1;
    }
    cout << ans << "\n";

    return 0;
}
