#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int nguoi, viec, ok;
int c[100][100];
vector<vector<int>> ans;
vector<int> a(100);
int res = INT_MAX;
void sinh()
{
    int i = viec - 1;
    while (i > 0 && a[i] > a[i + 1])
        i--;
    if (i == 0)
        ok = 0;
    else {
        int j = viec;
        while (j > i && a[j] < a[i])
            j--;
        swap(a[i], a[j]);
        sort(a.begin() + i + 1, a.begin() + viec + 1);
    }
}
void check()
{
    int sum = 0;
    for (int i = 1; i <= nguoi; i++) {
        sum += c[i][a[i]];
    }
    if (sum < res) {
        res = sum;
        ans.clear();
        ans.push_back(a);
    } else if (sum == res)
        ans.push_back(a);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    nguoi = viec = n;
    for (int i = 1; i <= nguoi; i++) {
        for (int j = 1; j <= viec; j++)
            cin >> c[i][j];
    }
    for (int i = 1; i <= viec; i++)
        a[i] = i;
    ok = 1;
    while (ok) {
        check();
        // for (int i = 1; i <= viec; i++)
        //     cout << a[i] << " ";
        // cout << "\n";
        sinh();
    }
    cout << res << '\n';

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 1; j <= viec; j++) {
            printf("Man%d->Job%d||", j, ans[i][j]);
        }
        cout << "\n";
    }

    return 0;
}
