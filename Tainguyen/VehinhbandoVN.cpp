// n = 4
// ****
// *
// *
// **** *
//    *
//    *  **
// ****  **
#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m = 2 * n - n / 4;
    int c1 = n + n / 2 - n / 4, c2 = 2 * n - n / 2;
    for (int i = 1; i <= n / 4; i++) {
        for (int j = 1; j <= n; j++)
            cout << "*";
        for (int j = n + 1; j <= 2 * n; j++)
            cout << " ";
        cout << "\n";
    }
    for (int i = n / 4 + 1; i <= (n - n / 4); i++) {
        for (int j = 1; j <= n / 4; j++)
            cout << "*";
        for (int j = (n / 4 + 1); j <= 2 * n; j++)
            cout << " ";
        cout << "\n";
    }
    for (int i = (n - n / 4) + 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << "*";
        for (int j = (n + 1); j <= c1; j++)
            cout << " ";
        for (int j = c1 + 1; j <= c1 + n / 4; j++)
            cout << "*";
        for (int j = c1 + 1 + n / 4; j <= 2 * n; j++)
            cout << " ";
        cout << "\n";
    }
    for (int i = (n + 1); i <= m - n / 2; i++) {
        for (int j = 1; j <= n - n / 4; j++)
            cout << " ";
        for (int j = n + 1 - n / 4; j <= n; j++)
            cout << "*";
        for (int j = n + 1; j <= 2 * n; j++)
            cout << " ";
        cout << "\n";
    }
    for (int i = m + 1 - n / 2; i <= m - n / 4; i++) {
        for (int j = 1; j <= n - n / 4; j++)
            cout << " ";
        for (int j = n + 1 - n / 4; j <= n; j++)
            cout << "*";
        for (int j = n + 1; j <= c2; j++)
            cout << " ";
        for (int j = c2 + 1; j <= 2 * n; j++)
            cout << "*";
        cout << "\n";
    }
    for (int i = m + 1 - n / 4; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << "*";
        for (int j = n + 1; j <= c2; j++)
            cout << " ";
        for (int j = c2 + 1; j <= 2 * n; j++)
            cout << "*";
        cout << "\n";
    }
}