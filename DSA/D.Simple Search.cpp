#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(5e5+7)
using namespace std;
ll a[nmax];
//int BSearch(int n, int x, int l, int r){
//	while ( l <= r){
//		int mid = (l+r)/2;
//		if ( a[mid] == x)
//			return 1;
//		else if ( a[mid] < x)
//			l = mid + 1;
//		else
//			r = mid - 1;
//	}
//	return 0;
//}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		ll n, k;
		cin >> n >> k;
		unordered_map<ll, ll> mp;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		ll cnt = 0;
		for (auto &x: mp){
			if ( x.first == k - x.first)
				cnt += x.second * ( x.second - 1)/ 2;
			else if(mp.count(k - x.first))
				cnt += x.second * mp[k - x.first];
			x.second = 0;
		}
		cout << cnt << "\n";
	}
}
