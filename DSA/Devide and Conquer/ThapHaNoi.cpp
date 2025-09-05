#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// n la so dia=> co 2^n - 1 buoc. duoc chia lam 3 phan.
void TowerHN(int n, int k, char A, char B, char C)
{
    if (k == (1 << n) / 2) { // luc nay chi con 1 dia
        cout << n << " " << A << " " << C << "\n";
        return;
    }
    if (k < (1 << n) / 2) // so buoc chuyen n dia tu A sang C < 2^n /2. thi no cung chinh la so buoc cua viec chuyen n-1 dia tu A sang B
        TowerHN(n - 1, k, A, C, B);
    else
        TowerHN(n - 1, k - (1 << n) / 2, B, A, C); // tong co k buoc, neu k > 2^n/2. thi buoc thu k chuyen n dia tu A sang C chinh la buoc thu k - 2^n/2 cua viec chuyen n-1 dia tu B sang C
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    int dem = 1;
    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            return 0;
        cout << "Case " << dem << ": ";
        TowerHN(n, k, 'A', 'B', 'C');
        dem++;
    }
    return 0;
}
