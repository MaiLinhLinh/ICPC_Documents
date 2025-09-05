#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
/*
mang res[] luu ket qua
Duyet mang A tu cuoi ve dau:
    pop cho den khi stack rong hoac gia tri tai top() > A[i]
    neu stack rong thi res[i] = -1( khong co so nao ben phai lon hon a[i])
    nguoc lai thi res[i] = top()
    push a[i] vao stack;
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res[n + 2] = { 0 }; // luu ket qua
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}
