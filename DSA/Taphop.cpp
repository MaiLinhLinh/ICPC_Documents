#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e7 + 7)
using namespace std;
/*
y tuong sinh nhi phan, chon day nhi phan k so 1( tuc la so nao dc chon lam to hop se ung voi bit 1)
day nhi phan k so 1 se cho ra to hop k phan tu
*/
int n, k, s, a[nmax], check;
void init()
{
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        check = 0;
    else
        a[i] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0)
            return 0;
        init();
        check = 1;
        int cnt = 0;
        while (check) {
            int dem = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1)
                    dem++; // dem so bit 1 cua 1 day nhi phan duoc sinh ra
            }
            if (dem == k) { // neu dem = k
                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    //  cout << a[i];
                    sum += i * a[i]; // tinh tong cua to hop tuong ung voi day nhi phan do
                }
                // cout << " "
                //      << sum << "\n";
                if (sum == s) {
                    cnt++;
                }
            }
            sinh();
        }
        cout << cnt << "\n";
    }
    return 0;
}
