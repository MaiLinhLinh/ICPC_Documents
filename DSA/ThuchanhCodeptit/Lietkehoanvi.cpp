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
int n, m, ok;
int a[15];

void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j > i && a[j] < a[i])
            j--;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ok = 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (ok) {
        if (a[1] == m) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh();
    }

    return 0;
}
