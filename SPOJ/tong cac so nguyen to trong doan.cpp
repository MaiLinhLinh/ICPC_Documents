#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e5+5)
using namespace std;
int snt(int n){
	if ( n == 2 || n == 3)
		return 1;
	if ( n < 2 || n % 2 == 0 || n % 3 == 0)
		return 0;
	for (int i = 5; i * i <= n; i +=  6){
		if ( n % i == 0 || n % (i+2) == 0)
			return 0;
	}
	return 1;
}
// neu n la so nguyen to => so cach + 1;
// neu khong thi xet den n/2; 
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sang();
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int cnt = 0;
		if (snt(n))
			cnt++;
		for (int i = 0; i + i <= n; i++){
			int ans = 0;
			if (snt(i)){
				for (int j = i; prime[j] + prime[j] <= n; j++){
					ans += prime[j];
					//cout << ans << "\n";
					if ( ans == n)
						cnt++;
					else if (ans > n)
						break;
				}
		}
		cout << cnt << "\n";
	}
}
