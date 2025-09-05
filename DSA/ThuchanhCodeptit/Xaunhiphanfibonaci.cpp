#include <bits/stdc++.h>
using namespace std;
int n, ok;
int a[20];
int f[93];
void Fibo()
{
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; i++)
        f[i] = f[i - 1] + f[i - 2];
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Fibo();
    cin >> n;
    ok = 1;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    int d = 1;
    int k = 2;
    while (ok) {
        if (d == f[k]) {
            cout << d << ": ";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            k++;
        }
        d++;
        sinh();
    }
    return 0;
}