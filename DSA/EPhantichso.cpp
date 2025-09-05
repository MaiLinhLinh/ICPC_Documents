#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// 5, 4 >= 1, 3 >= 1 >=1,..=> vi tri can xet se co gia tri = gia tri cua vi tri truoc giam dan ve 1
// de quy 3 dau vao: vi tri hien tai can tinh gtri, gia tri ngay truoc vi tri do, tong tu vi tri 1 den vi tri i - 1
int n, a[100];
void Try(int i, int pre, int sum)
{
    for (int j = pre; j >= 1; j--) {
        a[i] = j; // gan gia tri cho vi tri i
        if (sum + a[i] > n)
            continue;
        else if (sum + a[i] == n) { // neu tong( tu vi tri 1 den i) = n thi in ra cac so
            cout << "(";
            for (int x = 1; x <= i; x++) {
                cout << a[x];
                if (x != i)
                    cout << " ";
                else
                    cout << ") ";
            }
        } else // neu tong ( tu vi tri 1 den i) < n thi xet vi tri i+1
            Try(i + 1, a[i], sum + a[i]); // luc nay pre la a[i], sum la sum + a[i]
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
        Try(1, n, 0); // bat dau la vi tri 1, mac dinh vi tri nay giam tu n ve 1 => pre = n, sum = 0
        cout << "\n";
    }
}
