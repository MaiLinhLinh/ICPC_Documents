//
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e7 + 7)
using namespace std;
bool prime[nmax]; // sang nguyen to
vector<int> nt;
void sang()
{
    prime[0] = prime[1] = true; // khong la nt
    for (int i = 2; i * i <= nmax; i++) {
        if (!prime[i])
            for (int j = i * i; j <= nmax; j += i)
                prime[j] = true;
    }
    for (int i = 2; i <= nmax; i++) {
        if (!prime[i])
            nt.push_back(i);
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
        for (int i = 0; nt[i] * nt[i] <= n && i < nt.size(); i++) {
            if (n % nt[i] == 0) {
                int dem = 0;
                while (n % nt[i] == 0) {
                    dem++;
                    n /= nt[i];
                }
                cout << nt[i] << " " << dem << "\n";
            }
        }
        if (n > 1)
            cout << n << " 1\n";
        cout << "\n";
    }
    return 0;
}