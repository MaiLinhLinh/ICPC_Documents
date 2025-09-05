#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, hang[100], chinh[100], phu[100];
int cnt = 0;
void Try(int j)
{
    for (int i = 1; i <= n; i++) {
        if (hang[i] == 0 && chinh[i - j + n] == 0 && phu[i + j - 1] == 0) {
            hang[i] = chinh[i - j + n] = phu[i + j - 1] = 1;
            if (j < n)
                Try(j + 1);
            else {
                cnt++;
            }
            hang[i] = chinh[i - j + n] = phu[i + j - 1] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 0;
        memset(hang, 0, sizeof(hang));
        memset(chinh, 0, sizeof(chinh));
        memset(phu, 0, sizeof(phu));
        Try(1);
        cout << cnt << "\n";
    }
    return 0;
}
