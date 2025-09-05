#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e9+7)
ll f[7];
// cu 6 so thi lap lai 1 lan
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll x, y, n;
	cin >> x >> y >> n;
	//cout << n % 6  << "\n";
	f[1] = x;
	f[2] = y;
	for (int i = 3; i <= 6; i++){
		f[i] = (f[i-1] % mod - f[i-2] % mod) % mod;
	}
	//for (int i = 1; i <= 6; i++)
	//	cout << f[i] << " ";
	//cout << "\n";
	n %= 6;
	//cout << f[n] << "\n";
	if (n == 0)
		n = 6;
	if (f[n] >= 0)
		cout << f[n] << "\n";
	else if (f[n] < 0)
		cout << mod + f[n] << "\n";
}