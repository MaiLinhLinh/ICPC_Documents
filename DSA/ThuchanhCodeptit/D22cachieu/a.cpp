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
int n, k, ok;
int a[10], b[10];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    set<pair<int, vector<int>>> se;
    ok = 1;
    while (ok) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1)
                sum += b[i];
        }
        if (sum > 0 && sum < k) {
            vector<int> tmp;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1)
                    tmp.push_back(i);
            }
            se.insert({ sum, tmp });
        }
        sinh();
    }
    if (se.size() == 0) {
        cout << "-1\n";
    } else {
        for (auto x : se) {
            vector<int> v = x.second;
            int sum = x.first;
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << "\n";
            cout << "Sum = " << sum << "\n";
        }
    }

    return 0;
}
