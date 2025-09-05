#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
string anstring(string s)
{
    string prefix = "";
    stack<char> st;
    for (auto x : s) {
        if (isalpha(x))
            prefix += x;
        else if (x == '(')
            st.push(x);
        else if (x == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(st.top()) >= precedence(x)) {
                prefix += st.top();
                st.pop();
            }
            st.push(x);
        }
    }
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }
    return prefix;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string ans = anstring(s);
    cout << ans << "\n";
    return 0;
}
