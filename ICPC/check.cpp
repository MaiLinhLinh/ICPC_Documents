#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
set<ll> perfectnum;
void Lucky()
{
    queue<string> q;
    for (int i = 1; i <= 9; i++) {
        q.push(to_string(i));
    }
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        long long k = stoll(x);
        perfectnum.insert(k);
        if (x.size() < 18) {
            if (k % 10 == 0) {
                string a = x + to_string(k % 10 + 1);
                string b = x + to_string(k % 10 + 0);
                q.push(a);
                q.push(b);
            } else {
                string e = x + to_string(k % 10 - 1);
                string f = x + to_string(k % 10 + 1);
                string d = x + to_string(k % 10 + 0);
                q.push(e);
                q.push(f);
                q.push(d);
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
