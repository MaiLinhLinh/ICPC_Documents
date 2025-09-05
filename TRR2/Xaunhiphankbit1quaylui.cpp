#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int n, k;
int a[nmax];

void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Try(int i, int cnt, bool check)
{
    if (i == n + 1) {
        if (check)
            in();
        return;
    }
    a[i] = 0;
    Try(i + 1, 0, check);
    if (cnt < k) {
        if (check && cnt == k - 1)
            return;

        a[i] = 1;
        if (!check && cnt == k - 1)
            Try(i + 1, cnt + 1, 1);
        else
            Try(i + 1, cnt + 1, check);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n;
    Try(1, 0, 0);

    return 0;
}
