#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e7+5)
// luu y cach nhan doi mot 2 phan tu voi nhau ma ko duyet 2 for
// su dung 1 mang thu 2 co n+1 phan tu. se tinh tong all ptu phia sau
// phan tu minh chon de nhan
// vi du 1 3 7 11. chon 3 de nhan thi se la 3 * ( 7 + 11)
// a[1] = 3. b[2] = tong all phan tu phia sau tu chi so 2. b[2] = 7+11 = 18;
// cong don all phan tu phia sau. b[i] = a[i] + b[i+1]
// cong don all phan tu phia trc b[i] = b[i-1] + a[i]
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int b[n+1] = {0};
	ll sum = 0;
	for (int i = n-1; i >= 0; --i)
		b[i] = a[i] + b[i+1];
	for ( int i = 0; i < n; ++i)
		sum += 1ll * a[i] * b[i+1];
	cout << sum << "\n";
}