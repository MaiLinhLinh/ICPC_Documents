#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;
//g[1] = b[1];
//g[2] = b[2] ^ b[1];
//g[3] = b[3] ^ b[2];( bien ma nhi phan => gray theo thu tu 321 voi 1 la lsb)
int n, bin[100], check;
int gray[100];
void ktao(){
	for (int i = 1; i <= n; i++)
		bin[i] = 0;
}
void sinh(){
	// bat dau tu bit n, tim bit 0 dau tien.
	int i = n;
	while (i >= 1 && bin[i] == 1){
		bin[i] = 0;
		--i;
	}
	if (i == 0) // cau hinh cuoi 1111
		check = 0;
	else
		bin[i] = 1;
}
void in(){
	gray[1] = bin[1];
	for (int i = 2; i <= n; i++)
		gray[i] = bin[i] ^ bin[i-1];
	for (int i = 1; i <= n; i++)
		cout << gray[i];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		ktao();
		check = 1;
		while (check){
			in();
			sinh();
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
