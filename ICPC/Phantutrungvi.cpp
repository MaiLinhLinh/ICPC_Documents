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
vector<int> v;
int BSearch(int l, int r, int x)
{
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x)
            return mid;
        else if (v[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string c;
        cin >> c;
        if (c == "add") {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (c == "del") {
            int x;
            cin >> x;
            sort(v.begin(), v.end());
            int id = BSearch(0, v.size() - 1, x);
            v.erase(v.begin() + id);
        } else {
            sort(v.begin(), v.end());
            int id = (v.size() + 1) / 2;
            cout << v[id - 1] << "\n";
        }
    }
    return 0;
}
