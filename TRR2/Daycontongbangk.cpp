#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int k, n, check, a[205];
int b[205];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        check = 0;
    else
        a[i] = 1;
}
void in()
{
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * b[i];
    }
    if (sum == k) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1)
                cout << b[i] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    check = 1;
    while (check) {
        in();
        sinh();
    }
    return 0;
}
