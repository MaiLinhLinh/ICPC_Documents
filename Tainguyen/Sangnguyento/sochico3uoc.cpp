// la so chinh phuong couoclasnt
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7)
using namespace std;
int prime[nmax]; // sang so nt
void sang()
{
    prime[0] = prime[1] = 1; // khong la so nt
    for (int i = 2; i * i <= nmax; i++) {
        if (!prime[i])
            for (int j = i * i; j <= nmax; j += i)
                prime[j] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    sang();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int m = sqrt(n);
        if (m * m == n) {
            if (!prime[m])
                cout << "YES\n";
            else
                cout << "NO\n";
        } else
            cout << "NO\n";
    }
}