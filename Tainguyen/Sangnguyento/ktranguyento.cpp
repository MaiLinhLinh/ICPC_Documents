#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool nt[1000005];
int n = 1000000;

void sang()
{
    int can = sqrt(n);
    for (int i = 2; i <= n; ++i)
        nt[i] = 1;
    for (int i = 4; i <= n; i += 2)
        nt[i] = 0;
    for (int i = 3; i <= can; i += 2) {
        if (!nt[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            nt[j] = 0;
    }
}

int main()
{
    sang();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (nt[n])
            cout << "YES\n";
        else
            cout << "No\n";
    }
}