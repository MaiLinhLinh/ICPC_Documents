#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e7 + 7)
using namespace std;
int n, k;
vector<int> v;
int check(int x)
{
    int dem = 0;
    while (x) {
        int r = x % 2;
        if (r == 1)
            dem++;
        x /= 2;
    }
    return dem == k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (check(i))
            v.push_back(i);
    }
    if (v.size() == 0)
        cout << "No\n";
    else {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        cout << v.size();
    }

    return 0;
}
