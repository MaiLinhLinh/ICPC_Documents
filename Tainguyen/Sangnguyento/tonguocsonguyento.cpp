// Cho N
//  số nguyên. Hãy phân tích các số nguyên đã cho dưới dạng tích của các thừa số nguyên tố, sau đó tính tổng các ước số nguyên tố này.
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7)
using namespace std;
int snt[nmax]; // mang luu uoc so nt nho nhat
void sang()
{
    for (int i = 2; i * i <= nmax; i++) {
        if (!snt[i]) {
            snt[i] = i;
            for (int j = 2 * i; j <= nmax; j += i)
                snt[j] = i;
        }
    }
    int m = sqrt(nmax);
    for (int i = m; i <= nmax; i++)
        if (!snt[i])
            snt[i] = i;
}
long long cal(int n)
{
    ll sum = 0;
    while (n != 1) {
        sum += snt[n];
        n /= snt[n];
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    sang();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        int a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += cal(a[i]);
        }
        cout << sum << "\n";
    }
}