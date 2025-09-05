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
int uoc[nmax];
bool prime[nmax];
void sang()
{
    prime[0] = prime[1] = 1; // khong la so nguyen to
    for (int i = 2; i < nmax; i++) {
        if (!prime[i]) {
            uoc[i] = i;
            for (int j = i + i; j < nmax; j += i) {

                uoc[j] = i;
                prime[j] = 1;
            }
        }
    }
}
ll prefixSum[nmax];
void calc()
{
    prefixSum[2] = 2;
    prefixSum[3] = 5;
    for (int i = 4; i < nmax; i++)
        prefixSum[i] = prefixSum[i - 1] + uoc[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sang();
    calc();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        ll sum = prefixSum[r] - prefixSum[l - 1];
        cout << sum << "\n";
    }

    return 0;
}
