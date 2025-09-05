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
/* tích có hướng u(u1,u2) với v(v1,v2) = u1v2 - u2v1 == 0 thì 3 điểm thẳng hàng*/
ll nCk[305][305];
int n, k;
void tohop()
{
    for (int i = 0; i < 302; i++) {
        nCk[0][i] = 1;
        nCk[i][i] = 1;
    }
    for (int i = 1; i <= 302; i++) {
        for (int j = i + 1; j <= 302; j++)
            nCk[i][j] = nCk[i - 1][j - 1] + nCk[i][j - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    tohop();
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        int x1 = v[i].first, y1 = v[i].second;
        for (int j = i + 1; j < v.size(); j++) {
            int x2 = v[j].first, y2 = v[j].second;
            for (int k = j + 1; k < v.size(); k++) {
                int x3 = v[k].first, y3 = v[k].second;
                if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) == 0)
                    cnt++;
            }
        }
    }
    cout << nCk[3][n] - cnt << "\n";
    return 0;
}
