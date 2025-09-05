#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<int> a(50, 0);
vector<vector<int>> ans;
int day, guest;
int c[50][50];
int ok, maxx = 0;
void sinh()
{
    int i = guest;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i] = 1;
}
void check(vector<int>& a)
{
    int res = 0;
    for (int i = 1; i <= day; i++) {
        int cnt = 0;
        for (int j = 1; j <= guest; j++) {
            if (a[j] == 1 && c[j][i] == 1)
                cnt++;
        }
        if (cnt == 1)
            res++;
        else if (cnt > 1)
            return;
    }
    if (res > maxx) {
        maxx = res;
        ans.clear();
        ans.push_back(a);
    } else if (res == maxx)
        ans.push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> guest >> day;
    for (int i = 1; i <= guest; i++) {
        for (int j = 1; j <= day; j++)
            cin >> c[i][j];
    }
    ok = 1;
    while (ok) {
        check(a);
        sinh();
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 1; j <= guest; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
