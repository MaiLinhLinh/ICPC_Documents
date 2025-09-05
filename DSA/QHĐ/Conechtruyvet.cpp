#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
using namespace std;
// in ra chi so cua cac cot duoc chon
int h[nmax];
int dp[nmax]; // chi phi toi thieu de di den cot i
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int pos[n + 2];
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    pos[1] = 0;
    pos[2] = 1;
    for (int i = 3; i <= n; i++) {
        if (dp[i - 1] + abs(h[i - 1] - h[i]) <= dp[i - 2] + abs(h[i - 2] - h[i])) {
            dp[i] = dp[i - 1] + abs(h[i - 1] - h[i]);
            pos[i] = i - 1;
        } else {
            dp[i] = dp[i - 2] + abs(h[i - 2] - h[i]);
            pos[i] = i - 2;
        }
    }
    vector<int> v;
    int ind = n;
    while (ind != 0) {
        v.push_back(ind);
        ind = pos[ind];
    }
    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";
    return 0;
}
