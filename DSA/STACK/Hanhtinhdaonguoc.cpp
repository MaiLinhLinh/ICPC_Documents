#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    stack<char> st_al;
    stack<char> st_num;
    int m = s.size();
    for (int i = m - 1; i >= 0; i--) {
        if (isdigit(s[i]))
            st_num.push(s[i]);
    }
    for (int i = 0; i < m; i++) {
        if (isalpha(s[i]))
            st_al.push(s[i]);
    }
    while (!st_al.empty()) {
        cout << st_al.top();
        st_al.pop();
    }
    cout << "\n";
    while (!st_num.empty()) {
        cout << st_num.top();
        st_num.pop();
    }
    return 0;
}
