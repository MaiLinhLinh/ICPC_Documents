#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// day ngoac dung dai nhat khong lien tiep
// moi lan tim duoc mot cap ngoac dung thi do dai tang len 2
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int res = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push('(');
        else if (!st.empty()) {
            st.pop();
            res += 2; // moi lan tim duoc 1 dau ngoac dung, ket qua + 2
        }
    }
    cout << res << "\n";
    return 0;
}
