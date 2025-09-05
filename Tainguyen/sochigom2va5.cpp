// Ngày sinh của Hòa chỉ tồn tại các số 2
//  và 5
//  nên là Hòa là một người rất thích các chữ số 2
//  và 5
// .

// Hòa quy định rằng các số "ĐẶC BIỆT" đối với Hòa sẽ là những số chỉ tồn tại 2
//  số 2
//  hoặc 5
//  hoặc có cả 2
//  số 2
//  và 5
// , ví dụ 2,5,22,25,52,55,222,225,
// ...

// Vốn rất yêu thích toán nhưng học suýt trượt môn Hòa liền đưa ra đề bài toán như sau: Cho hai số R
//  và L
// , hãy đếm các chữ số "ĐẶC BIỆT" trong đoạn R
//  và L
//  ([R,L])
// . Nếu số đếm cũng là một chữ số đặc biệt thì in ra YES
// , ngược lại in ra NO
// .
#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int check(int n)
{
    int m = n;
    while (n) {
        int r = n % 10;
        if (r != 2 && r != 5)
            return 0;
        n /= 10;
    }
    return m > 1;
}
int prefix[nmax];
void calc()
{
    prefix[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        prefix[i] = prefix[i - 1];
        if (check(i))
            prefix[i]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    calc();
    int t;
    cin >> t;
    while (t--) {
        int r, l;
        cin >> r >> l;
        if (r > l)
            swap(l, r);
        int ans = prefix[l] - prefix[r - 1];
        cout << ans << "\n";
        if (check(ans))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}