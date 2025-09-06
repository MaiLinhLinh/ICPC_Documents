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
const long long INF = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;

    // dist[r] = tổng chữ số nhỏ nhất của một số không âm có phần dư r mod k
    // ta xem X = d1d2d3....dn thì mỗi lần thêm 1 chữ số cho X: X' = x * 10 + d => dư r' = (10 * r  + d) mod k
    vector<ll> dist(k, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {tổng chữ số, dư}

    // bắt đầu bằng các chữ số đầu tiên: 1 -> 9
    for (int d = 1; d <= 9; d++) {
        int r = d % k;
        if (dist[r] > d) {
            dist[r] = d;
            pq.push({ dist[r], r });
        }
    }
    // Dijktra:
    while (!pq.empty()) {
        auto [tong, du] = pq.top();
        pq.pop();
        if (tong > dist[du])
            continue;
        if (du == 0) {
            cout << tong;
            return 0; // đã tìm được số có tổng chữ số min và chia hết cho k
        }
        for (int d = 0; d <= 9; d++) {
            int r = (du * 10 + d) % k;
            if (dist[r] > tong + d) {
                dist[r] = tong + d;
                pq.push({ dist[r], r });
            }
        }
    }

    return 0;
}
