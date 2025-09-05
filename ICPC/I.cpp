#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
string tostring(int n)
{
    string s = "";
    while (n) {
        int r = n % 10;
        s += r + '0';
        n /= 10;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string ans = "";
        for (int i = a; i <= b; i++) {
            ans += tostring(i);
        }
        long long sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            sum += ans[i] - '0';
        }
        cout << sum << "\n";
    }
    return 0;
}
