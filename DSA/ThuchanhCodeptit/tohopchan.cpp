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
int n, k;
int a[20];

void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            int sum = 0;
            for (int x = 1; x <= k; x++)
                sum += a[x];
            if (sum % 2 == 0) {
                for (int x = 1; x <= k; x++)
                    cout << a[x] << " ";
                cout << "\n";
            }
        } else
            Try(i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Try(1);

    return 0;
}
