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
int n, ok;
int a[10];

void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (j > i && a[j] <= a[i])
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
    string s;
    cin >> s;
    int k;
    cin >> k;
    n = s.size();
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a' + 1;
    }
    sort(a + 1, a + n + 1);
    int d = 1;
    ok = 1;
    while (ok) {
        if (k == d) {
            for (int i = 1; i <= n; i++) {
                cout << char(a[i] - 1 + 'a');
            }
            break;
        }
        sinh();
        d++;
    }
    return 0;
}
