#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// voi so n, co n - 1 buoc bien doi, do dai cuoi cung la 2 ^ n - 1 phan tu
void Vitri(int n, int k)
{
    if (k == (1 << n) / 2) { // neu k la vi tri chinh giua thi vi tri do co gia tri = n
        cout << n << "\n";
        return;
    }
    if (k < (1 << n) / 2)
        Vitri(n - 1, k);
    else
        Vitri(n - 1, k - (1 << n) / 2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Vitri(n, k);
    }
    return 0;
}
