#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int checkdau(int X[])
{
    for (int i = 1; i <= k; i++) {
        if (X[i] != i)
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int check = 0;
        int X[1005];
        for (int i = 1; i <= k; i++)
            cin >> X[i];
        if (checkdau(X)) {
            check = 1;
            for (int i = n - k + 1; i <= n; i++)
                cout << i << " ";
        } else {
            int i = k;
            // cout << X[i] - X[i - 1] << "\n";
            while (i >= 2 && X[i] - X[i - 1] == 1)
                i--;
            // cout << i << "\n";
            X[i]--;
            if (i < k)
                X[k] = n;
            for (int j = k - 1; j >= i + 1; j--)
                X[j] = X[j + 1] - 1;
            for (int j = 1; j <= k; j++)
                cout << X[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
