// Cho 2
//  số nguyên dương L
//  và R
// , in ra các số nguyên tố trong đoạn [L,R]
// .
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7);
using namespace std;
// tao mang có r - l + 1 phan tu de sang nt;
void sang(ll l, ll r)
{
    ll prime[r - l + 1]; // xem prime[l] = prime[0] -> prime[l+1]= prime[1]---> prime[r] = prime[r-l]
    for (ll i = 0; i <= r - l + 1; i++)
        prime[i] = 1;
    for (ll i = 2; i * i <= r; i++) { // 1 so tu l den r, neu co uoc thi nó se co uoc trong doan 2 den can r
        for (ll j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i) // duyet cac boi cua i trong doan l den r
            prime[j - l] = 0; // gan cac boi do khong la nt, duoi dang chi so( prime[j] = prime[j-l])
    }
    for (ll i = max(l, 2ll); i <= r; i++) { // duyet tu max(l,2) de loai cac th l = 0, 1 thi chi can duyet tu 2
        if (prime[i - l])
            cout << i << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        sang(l, r);
        cout << "\n";
    }
}