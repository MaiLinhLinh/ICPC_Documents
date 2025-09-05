#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll h[n + 2];
    stack<ll> st;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    h[n] = 0;
    st.push(0);
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[i] <= h[st.top()]) {
            ll CR = h[st.top()];
            st.pop();
            ll CD = i; // tu 0 den i-1
            if (!st.empty())
                CD -= (st.top() + 1); // tu 0 den st.top()( CD la tu st.top() truoc khi pop() den i-1)
            ll tmp = min(CD, CR); // tim canh hinh vuong
            res = max(res, tmp * tmp);
        }
        st.push(i);
    }
    cout << res << "\n";
    return 0;
}
