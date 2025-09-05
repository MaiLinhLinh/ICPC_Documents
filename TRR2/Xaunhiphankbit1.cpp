#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

#include <iostream>
#define ll long long
#define nmax int(1e6)
using namespace std;
int n, k, check;
int a[nmax];

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
int ktra(int a[])
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int dem = 0;
        if (a[i] == 1 && i <= n - k + 1) {
            for (int j = i + 1; j <= i + k; j++) {
                if (dem == k - 1)
                    cnt++;
                if (a[j] == 1)
                    dem++;
                else
                    dem = 0;
            }
        }
    }
    if (cnt == 1)
        return 1;
    else
        return 0;
}
int main()
{
    cin >> k >> n;
    check = 1;
    while (check) {
        if (ktra(a) == 1) {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
        sinh();
    }
    return 0;
}

