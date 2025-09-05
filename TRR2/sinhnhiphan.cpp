#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, a[100], check;
void ktao()
{
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        a[i] = x == 'A' ? 1 : 0;
    }
}
void sinh()
{
    // bat dau tu bit n, tim bit 0 dau tien.
    int i = n;
    while (i >= 1 && a[i] == 1) {
        a[i] = 0;
        --i;
    }
    if (i == 0) // cau hinh cuoi 1111
        check = 0;
    else
        a[i] = 1;
}
void in()
{
    for (int i = 1; i <= n; i++)
        if (a[i])
            cout << "A" << " ";
        else
            cout << "B" << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ktao();
    check = 1;
    for (int i = 1; i <= 5; i++) {
        sinh();
        in();
        cout << "\n";
    }
}
