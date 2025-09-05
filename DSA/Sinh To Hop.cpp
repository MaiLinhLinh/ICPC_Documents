#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;
int n, k, a[10], check;
void ktao(){
	for (int i = 1; i <= k; i++)
		a[i] = i;
}
void sinh(){
	int i = k;
	while ( i >= 1 && a[i] == n - k + i)
		i--;
	if ( i == 0)
		check = 0;
	else{
		a[i]++;
		int j = i+1;
		while (j <= k){
			a[j] = a[j-1] + 1;
			j++;
		}
	}
	
}
void in(){
	for (int i = 1; i <= k; i++)
		cout << a[i];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	ktao();
	check = 1;
	while (check){
		in();
		sinh();
		cout << "\n";
	}
}
