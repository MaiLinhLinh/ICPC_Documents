#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;
int n, a[10], check;
void ktao(){
	for (int i = 1; i <= n; i++)
		a[i] = i;
}
void sinh(){
	// bat dau tu cuoi, tim a[i] < a[i+1];
	int i = n - 1;
	while (i >= 1 && a[i] >= a[i+1])
			--i;
	if (i == 0)
		check = 0;
	else{
		int j = n;
		while (j >= i && a[j] <= a[i])
			j--;
		swap(a[i], a[j]);
		int l = i+1, r = n;
		while ( l <= r){
			swap(a[l], a[r]);
			l++;
			r--;
		}
		// reverse( a + i + 1, a+ n + 1);
	}
}
void in(){
	for (int i = 1; i <= n; i++)
		cout << a[i];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ktao();
	check = 1;
	while (check){
		in();
		sinh();
		cout << "\n";
	}

}
