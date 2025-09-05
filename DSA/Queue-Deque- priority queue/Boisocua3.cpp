#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

void inKQ(vector<int> a)
{
    for (int i = 9; i >= 0; i--)
        while (a[i]--)
            cout << i;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        priority_queue<int, vector<int>, greater<int>> pq[3];
        int n;
        cin >> n;
        int sum = 0;
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            sum += x;
            pq[x % 3].push(x);
        }
        if (sum == 0) {
            cout << 0;
        } else if (sum % 3 == 0) {
            inKQ(cnt);
        } else {
            int x = sum % 3;
            int y = 3 - x;
            if (!pq[x].empty()) {
                cnt[pq[x].top()]--;
                inKQ(cnt);
            } else if (pq[y].size() >= 2) {
                cnt[pq[y].top()]--;
                pq[y].pop();
                cnt[pq[y].top()]--;
                inKQ(cnt);
            } else {
                cout << -1;
            }
        }
        cout << "\n";
    }
    return 0;
}
