#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int Xopt[1000];
int x[1000];
int c[100], a[100];
int Fopt;

void Try(int i, int S, int b, int g)
{
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i < n)
            g = S + c[i] * x[i] + b * c[i + 1] / a[i + 1];
        if (i == n && S + c[i] * x[i] > Fopt) {
            Fopt = S + c[i] * x[i];
            for (int k = 1; k <= n; k++)
                Xopt[k] = x[k];
            return;
        }
        if (i < n && S + c[i] * x[i] + b * c[i + 1] / a[i + 1] > Fopt && b - c[i] *x[i] >= 0) {
            Try(i + 1, S + c[i] * x[i], b - c[i] * x[i], S + c[i] * x[i] + b * c[i + 1] / a[i + 1]);
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    1 2 3 4 5 6
    1 3 6
    1 0 1 0 0 1

    return 0;
}
