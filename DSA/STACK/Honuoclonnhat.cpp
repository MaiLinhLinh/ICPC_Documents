#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, m;
ll MaxArray(int h[]) // hinh chu nhat lon nhat
{
    h[m] = 0;
    stack<int> st;
    st.push(0);
    ll ans = h[0];
    for (int j = 1; j <= m; j++) {
        while (!st.empty() && h[j] <= h[st.top()]) {
            ll CR = h[st.top()];
            st.pop();
            ll CD = j;
            if (!st.empty())
                CD -= (st.top() + 1);
            ans = max(ans, CR * CD);
        }
        st.push(j);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a[n + 1][m + 1];
    int h[m + 2] = { 0 };
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                h[j]++; // so luong so 1 lien tiep nhau trong 1 cot
            else
                h[j] = 0;
        }
        res = max(res, MaxArray(h)); // moi hang, deu tim dtich hinh chu nhat lon nhat
    }
    cout << res << "\n";
    return 0;
}
