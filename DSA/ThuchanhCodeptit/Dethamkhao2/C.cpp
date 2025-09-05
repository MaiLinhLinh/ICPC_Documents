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
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin, s);
        stack<int> st;
        int t = 0, ok = 0;
        int res[s.size() + 1];
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                t++;
                cout << t << " ";
                st.push(t);
            } else if (s[i] == ')') {
                cout << st.top() << " ";
                st.pop();
            }
        }

        cout << "\n";
    }

    return 0;
}
