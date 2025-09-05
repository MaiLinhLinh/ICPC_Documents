#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// tu tuong: sinh hoan vi cho tung hang.
// sinh hoan vi tu 1 den n, moi hoan vi la n cot => moi hang tu 1 den n la cot tuong ung hoan vi
// vidu hoan vi 3 2 1 thi ta co hang 1 lay cot 3, hang 2 lay cot 2, hang 3 lay cot 1
// hay hoan vi 1 2 3 thi hang 1 lay cot 1, hang 2 lay cot 2, hang 3 lay cot 3
//=> sinh hoan vi tu 1 den n la hoan vi cua n cot, moi hoan vi khong trung nhau, moi hang lay 1 cot thi se cho ket qua
// khong trung hang khong trung cot
//=> y tuong de lam cac bai khong trung hang trung cot cua ma tran
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int b[n + 1];
    vector<int> v;
    for (int i = 1; i <= n; i++)
        b[i] = i;
    int cnt = 0;
    do {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i][b[i]];
        if (sum == k) {
            cnt++;
            for (int i = 1; i <= n; i++)
                v.push_back(b[i]);
        }
    } while (next_permutation(b + 1, b + n + 1));
    cout << cnt << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if ((i + 1) % (n) != 0)
            cout << " ";
        else
            cout << "\n";
    }
    return 0;
}
