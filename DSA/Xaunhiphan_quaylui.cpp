#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int a[100];
void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << "\n";
}
void Try(int i)
{
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n)
            in();
        else
            Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = 0;
    Try(1);
    return 0;
}
