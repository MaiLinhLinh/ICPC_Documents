#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, a[100], X, b[100];
vector<vector<int>> v;
bool check(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] > a[j])
                return 0;
        }
    }
    return 1;
}
void Try(int i, int remaining, vector<int>& v1)
{
    if (remaining == 0) {
        v.push_back(v1);
        return;
    }
    if (i == n)
        return;

    for (int j = i; j <= n; j++) {
        if (remaining >= a[j] && check(v1)) {
            v1.push_back(a[j]);
            Try(i, remaining - a[j], v1);
            v1.pop_back();
        }
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
        v.clear();
        cin >> n >> X;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        vector<int> v1;
        Try(1, X, v1);
        // for (auto x : v1)
        //     cout << x << " ";
        // cout << "\n";
        if (v.size() == 0)
            cout << "-1\n";
        else {
            cout << v.size() << " ";
            for (int i = 0; i < v.size(); i++) {
                cout << "{";
                for (int j = 0; j < v[i].size() - 1; j++)
                    cout << v[i][j] << " ";
                cout << v[i][v[i].size() - 1] << "} ";
            }
            cout << "\n";
        }
    }
    return 0;
}
