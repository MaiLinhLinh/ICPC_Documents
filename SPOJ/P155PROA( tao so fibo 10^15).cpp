#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+5)
using namespace std;
// tao struct ma tran. dinh nghia toan tu nhan ma tran
struct matran{
	ll x[2][2];
	friend matran operator * (matran a, matran b){
		matran c;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				c.x[i][j] = 0;
				for (int k = 0; k < 2; k++){
					c.x[i][j] += a.x[i][k] * b.x[k][j];
					c.x[i][j] %= mod;
				}
			}
		}
		return c;
	}
};
matran binpow(matran a, ll n){
	if ( n == 1)
		return a;
	matran tmp = binpow(a, n/2);
	if ( n % 2 == 1)
		return tmp * tmp * a;
	return tmp * tmp;
}
// cong thuc tinh tong fibo f1 --> fn = f(n+2) - 1;
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a1, n;
	cin >> a1 >> n;
	matran a;
	a.x[0][0] = a.x[0][1] = a.x[1][0] = 1;
	a.x[1][1] = 0;
	matran res = binpow(a, n);
	//cout << res.x[0][0] << " " << res.x[0][1] << "\n";
	ll sum = res.x[0][0] + res.x[0][1] - 1;
	ll ans = sum * a1;
	ans %= mod;
	cout << ans << "\n";
}
