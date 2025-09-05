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
int n, k, ok;
int a[25];
ll f[93];
void Fibo()
{
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; i++)
        f[i] = f[i - 1] + f[i - 2];
}

void sinh()
{
    int i = k;
    while (i >= 1 && a[i] == n - k + i)
        i--;
    if (i == 0)
        ok = 0;
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Fibo();
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    ok = 1;
    int d = 1, t = 2;
    while (ok) {
        if (d == f[t]) {
            cout << d << ": ";
            for (int i = 1; i <= k; i++)
                cout << a[i] << " ";
            cout << "\n";
            t++;
        }
        d++;
        sinh();
    }

    return 0;
}
