#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t
	int k;
	cin >> k;
	int x;
	map<int, int> mp;
	while ({
		mp[x++];
	}
	int cnt = 0;
	for (auto x: mp){
		if (x.first == k - x.first)
			cnt += x.second * (x.second + 1) / 2;
		else{
			cnt += x.second * mp[k - x.first];
		}
	}
	cout << cnt << "\n";
}
