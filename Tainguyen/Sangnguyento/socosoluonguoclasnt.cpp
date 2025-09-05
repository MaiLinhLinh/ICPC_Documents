// Số hoàn hảo là số có số lượng ước của nó là một số nguyên tố.

// Hãy tìm trong đoạn cho trước [A,B]
//  xem có bao nhiêu số hoàn hảo?
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7)
using namespace std;
int prime[nmax]; // dem so luong cac uoc
void sang()
{
    prime[1] = 1;
    for (int i = 2; i <= nmax; i++)
        prime[i] = 2;
    for (int i = 2; i <= nmax; i++) {
        for (int j = 2 * i; j <= nmax; j += i)
            prime[j]++;
    }
}
int snt(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int pre[nmax];
void cal()
{
    pre[1] = 0;
    for (int i = 2; i <= nmax; i++) {
        pre[i] = pre[i - 1];
        if (snt(prime[i]))
            pre[i] = pre[i - 1] + 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    sang();
    cal();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }
}