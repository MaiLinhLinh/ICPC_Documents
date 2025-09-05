#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    vector<vector<int>> a(k + 1);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }

    vector<int> tmp = a[0];

    for (int i = 1; i <= k - 1; i++) { // duyet k-1 hang con lai
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int j = 0; j < k; j++) {
            pq.push({ tmp[j] + a[i][0], 0 });
        }
        for (int h = 0; h < k; h++) {
            auto [s, id] = pq.top();
            pq.pop();
            tmp[h] = s;
            if (id + 1 < k)
                pq.push({ s - a[i][id] + a[i][id + 1], id + 1 });
        }
    }
    for (auto x : tmp)
        cout << x << " ";
    
    

    return 0;
}