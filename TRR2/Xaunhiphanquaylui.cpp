#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n;
int a[200];
void in()
{

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Try(int i)
{
    if (i > n) {
        in();
        return;
    }
    // neu a[i] = 0
    a[i] = 0;
    Try(i + 1);
    // neu a[i] = 1
    a[i] = 1;
    Try(i + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(a, 0, sizeof(a));
    Try(1);
    return 0;
}
