#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// y tuong: 1 so la gia tri cua 1 doan con neu so do la so lon nhat cua doan do
// vi du 8 1 3 7 7 1 9: muon 7 (dau tien) la gia tri cua 1 doan con thi 7 phai la so lon nhat
// 7 la so lon nhat cua doan con dai nhat( tim so gan nhat ben trai > 7 va so gan nhat ben phai > 7)
// so doan con la x * y : x = 3( 1, 3, 7), y = 3(7, 7, 1)
// truong hop day co 2 so 7 thi se co 2 doan con trung nhau co gia tri = 7 nen khi cong gia tri doan con = 14( = tong cua cac so lon nhat trong doan con)

ll a[nmax];
ll l[nmax];
ll r[nmax];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st; // luu chi so cua so dau tien > a[i]
    // tim so dau tien ben trai > a[i]
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (!st.empty())
            l[i] = st.top() + 1; // st.top dang la chi so cua so gan nhat > a[i]
        else
            l[i] = 0; // truoc a[i] khong co so nao > a[i]
        st.push(i);
    }
    // tim so dau tien ben phai > a[i]
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (!st.empty())
            r[i] = st.top() - 1;
        else
            r[i] = n - 1;
        st.push(i);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll x = i - l[i] + 1;
        ll y = r[i] - i + 1;
        res = (res + (a[i] * ((x * y) % mod)) % mod) % mod;
    }
    cout << res << "\n";
    return 0;
}
