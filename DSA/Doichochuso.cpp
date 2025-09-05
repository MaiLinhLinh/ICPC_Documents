#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
void Try(string& s, string& MAX, int i, int cnt, int k)
{
    if (cnt == k || i == s.size() - 1)
        return;
    char maxx = s[i];
    for (int j = i + 1; j < s.size(); j++) {
        maxx = max(maxx, s[j]);
    }
    if (maxx == s[i])
        Try(s, MAX, i + 1, cnt, k);
    else {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[j] == maxx) {
                swap(s[i], s[j]);
                MAX = max(MAX, s);
                Try(s, MAX, i + 1, cnt + 1, k);
                swap(s[i], s[j]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string s, v;
        cin >> s;
        v = s;
        Try(s, v, 0, 0, k);

        cout << v << "\n";
    }
    return 0;
}
