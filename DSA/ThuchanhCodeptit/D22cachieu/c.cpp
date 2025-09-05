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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    int less_left[n + 1];
    int less_right[n + 1];
    // tim phan tu be hon ben trai
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            less_left[i] = 0;
        else
            less_left[i] = st.top();
        st.push(i);
    }
    // tim phan tu be hon ben phai
    st = stack<int>();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            less_right[i] = n + 1;
        else
            less_right[i] = st.top();
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int lenmax = less_right[i] - less_left[i] - 1;
        mp[lenmax].push_back(a[i]); // lenmax la do dai lon nhat nhan a[i] la min
    }

    multiset<int> se;
    for (int i = 1; i <= n; i++) {
        se.insert(a[i]); // them vao multiset cac gia tri min b tren cac doan do dai = 1;
    }
    for (int x = 1; x <= n; x++) {
        cout << *se.rbegin() << " ";
        // xoa cac gia tri min b chi thoa man voi doan do dai <= x
        for (auto v : mp[x]) {
            // debug(x, v);
            auto it = se.find(v);
            se.erase(it);
        }
    }

    return 0;
}
