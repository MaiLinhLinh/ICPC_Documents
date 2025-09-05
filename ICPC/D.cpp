#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
set<ll> perfectnum;
void Lucky()
{
    queue<ll> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        ll so = x % 10;
        perfectnum.insert(x);
        if (so == 0) {
            if (perfectnum.size() <= 100000) {
                q.push(x * 10 + so);
                q.push(x * 10 + so + 1);
            }

        } else {
            if (perfectnum.size() <= 100000) {
                q.push(x * 10 + so);
                q.push(x * 10 + so + 1);
                q.push(x * 10 + so - 1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Lucky();

    int n;
    cin >> n;
    int dem = 0;
    for (auto i : perfectnum) {
        dem++;
        if (dem == n) {
            cout << i;
            break;
        }
    }
    return 0;
}
