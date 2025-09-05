#include <bits/stdc++.h>
using namespace std;
int n, ok;
int a[15];
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 2) {
        a[i] = 0;
        i--;
    }
    if (i == 0)
        ok = 0;
    else
        a[i]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    ok = 1;
    int d = 1;
    while (ok) {
        if (d % 2) {
            cout << d << ": ";
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0)
                    cout << "A";
                else if (a[i] == 1)
                    cout << "B";
                else
                    cout << "C";
            }
            cout << "\n";
        }
        d++;
        sinh();
    }
}