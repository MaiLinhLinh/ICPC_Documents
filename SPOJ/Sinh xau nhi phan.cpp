#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+5)
using namespace std;
int n, check;
int a[25];
void sinh (){
	int i = n;
	while ( i >= 1 && a[i] == 1)
		i--;
	if ( i == 0)
		check = 0;
	else{
		a[i] = 1;
		for(int j = i + 1; j <= n; j++)
			a[j] = 0;
	}
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	check = 1;
	while(check){
		for (int i = 1; i <= n; i++)
			cout << a[i];
		cout << "\n";
		sinh();
	}
}
