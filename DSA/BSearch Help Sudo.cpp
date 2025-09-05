#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+5)
using namespace std;
int a[nmax];
int BSearch(int n, int x){
	int l = 0, r = n - 1;
	while (l <= r){
		int mid = (l + r) / 2;
		if ( a[mid] == x)
			return 1;
		else if (a[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	for( int i = 0; i < n; i++)
		cin >> a[i];
	if (BSearch(n, x))
		cout << "YES\n";
	else
		cout << "NO\n";
}
