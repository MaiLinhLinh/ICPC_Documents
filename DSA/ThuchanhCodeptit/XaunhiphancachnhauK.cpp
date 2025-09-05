#include <bits/stdc++.h>
using namespace std;
int n, k, ok;
int a[25];

int d = 0, t = 0;
void Try(int i)
{
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n) {
            if (d == t) {

                for (int x = 1; x <= n; x++)
                    cout << a[x];
                cout << "\n";
                t += k;
            }
            d++;
        } else
            Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    Try(1);
}