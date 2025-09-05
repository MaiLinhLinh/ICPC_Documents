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
    string s;
    cin >> s;
    stack<string> st;
    for (auto x : s) {
        if (isalpha(x))
            st.push(string(1, x));
        else {
            string fi = st.top();
            st.pop();
            string se = st.top();
            st.pop();
            string tmp = x + se + fi;
            st.push(tmp);
        }
    }
    cout << st.top() << "\n";
    return 0;
}
