#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, m, a[200], b[200];
void ktao(int x)
{
    for (int i = 1; i <= n - x; i++)
        b[i] = a[i];
}
void in(int x)
{
    cout << "[";
    for (int i = 1; i < n - x; i++)
        cout << a[i] << " ";
    cout << a[n - x] << "]\n";
}
void Try(int i)
{
    for (int j = 1; j <= n - i; j++)
        a[j] = b[j] + b[j + 1];
    if (i == n)
        return;
    ktao(i);
    in(i);
    Try(i + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        m = n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ktao(0);
        in(0);
        Try(1);
    }
    return 0;
}
