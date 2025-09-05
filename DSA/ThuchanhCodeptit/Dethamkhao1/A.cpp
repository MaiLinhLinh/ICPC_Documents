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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    a[0] = m;
    for (int i = 1; i < n; i++) {
        if (i < m)
            a[i] = i;
        else
            a[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(a + 1, a + n));

    return 0;
}
