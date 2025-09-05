#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        priority_queue<ll> pq;
        map<char, ll> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for (auto x : mp)
            pq.push(x.second);
        while (k--) {
            if (!pq.empty()) {
                ll tmp = pq.top();
                tmp--;
                pq.pop();
                pq.push(max(tmp, 0LL)); // khi k vuot qua do dai pq
            }
        }
        ll ans = 0;
        while (!pq.empty()) {
            ans += pq.top() * pq.top();
            pq.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}
