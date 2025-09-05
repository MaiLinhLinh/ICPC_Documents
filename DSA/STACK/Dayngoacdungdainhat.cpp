#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// lien tiep
// y tuong: lay dau ) tru di truoc dau ( bat dau 1 day ngoac dung.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    stack<int> st; // luu vi tri dau ngoac (
    st.push(-1); // push vi tri truoc vi tri bat dau cho truong hop s[0] = "("
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push(i);
        else {
            st.pop(); // xoa di phan tu vi tri dau "(" bat dau 1 day ngoac dung
            if (!st.empty())
                res = max(res, i - st.top()); // i - st.top(): vi tri dau ")" tru di vi tri ngay truoc dau "("
            else
                st.push(i); // (push vi tri truoc vi tri bat dau)
        }
    }
    cout << res << "\n";
    return 0;
}
