#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+5)
using namespace std;
int Bsearch( vector<ll> v, int l, int r, ll x){
	while ( l <= r){
		int mid = (l+r)/2;
		if ( v[mid] == x)
			return mid;
		else if ( v[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}
int check (ll n){
	ll x = sqrt(n);
	return x * x == n;
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector< ll> v;
		for (int i = 0; i < n; i++){
			ll x;
			cin >> x;
			v.push_back(x * x);
		}
		sort (v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < n - 2; i++){
			for (int j = i + 1; j < n-1; j++){
				ll c = v[i] + v[j];
				if(check(c)){
					if (Bsearch(v, j, n-1, c) != -1){
						cout << "YES\n";
						res = 1;
						break;
					}
				}
			}
		}
		if (res == 0)
			cout << "NO\n";
	}
}
