#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, S, t[100];
int ans = 100;
void Try(int i, ll currentSum, int currentCount)
{
    if (currentSum == S) {
        ans = min(ans, currentCount);
        return;
    }
    if (currentSum > S || currentCount >= ans || i == n + 1)
        return;
    for (int j = 0; j <= 1; j++) {
        Try(i + 1, currentSum + j * t[i], currentCount + j);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> S;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
            sum += t[i];
        }
        ans = 100;
        if (sum < S)
            cout << "-1\n";
        else {
            Try(1, 0, 0);
            if (ans == 100)
                cout << "-1\n";
            else
                cout << ans << "\n";
        }
    }
    return 0;
}
