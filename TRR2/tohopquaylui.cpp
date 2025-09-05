#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int n, k;
int a[200];
void in()
{
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Try(int i)
{	
	if( i > k){
		in();
		return;
	}
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
            Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    Try(1);
    return 0;
}
