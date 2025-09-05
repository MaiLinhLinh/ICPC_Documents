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
    int n, m;
    cin >> n >> m;
    long long ans = pow(2, n) + pow(3, m);
    string x = tostring(ans);
    cout << x[x.size() - 1];
    return 0;
}
