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
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tmp[n + 1];
    stack<int> st;
    // vi tri phan tu lon hon phan tu hien tai
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        if (!st.empty())
            tmp[i] = st.top();
        else
            tmp[i] = -1;
        st.push(i);
    }
    int res[n + 1];
    stack<int> stk;
    // phan tu nho hon phan tu trong mang a[]
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() >= a[i])
            stk.pop();
        if (!stk.empty())
            res[i] = stk.top();
        else
            res[i] = -1;
        stk.push(a[i]);
    }
    // mang tmp[] la luu chi so cua phan tu lon hon=> in ra phan tu nho hon cua mang tmp[]
    for (int i = 0; i < n; i++) {
        if (tmp[i] == -1)
            cout << "-1" << " ";
        else if (res[tmp[i]] == -1)
            cout << "-1 ";
        else
            cout << res[tmp[i]] << " ";
    }
    return 0;
}
