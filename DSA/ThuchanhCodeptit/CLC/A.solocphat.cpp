#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        vector<ll> ans;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            ans.push_back(stoll(x));
            if (x.size() < n) {
                q.push(x + "6");
                q.push(x + "8");
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}