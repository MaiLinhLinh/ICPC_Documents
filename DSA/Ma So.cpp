#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;
string a, b;
int n, check;

void sinh_alpha(){
	int i = n - 2;
	while( i >= 0 && a[i] >= a[i+1])
		--i;
	if( i == -1)
		check = 0;
	else{
		for (int j = n - 1; j > i; j--){
			if(a[j] > a[i]){
				swap(a[j], a[i]);
				sort(a.begin() + i + 1, a.end());
				break;
			}
		}
	}
}
void sinh_num(){
	int i = n - 1;
	while ( i >= 0 && (b[i] - '0') == n){
		--i;
	}
	if( i == -1)
		check = 0;
	else{
		b[i]++;
		for (int j = i + 1; j <= n - 1; j++){
			b[j] = '1';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 'A'; i < ('A' + n) ; i++)
		a += char(i);
	for(int i = 1; i <= n; i++)
		b += '1';
	check = 1;
	vector< string> al, num;
	while (check){
		al.push_back(a);
		sinh_alpha();
	}
	check = 1;
	while(check){
		num.push_back(b);
		sinh_num();
	}
	for(int i = 0; i < al.size(); i++){
		for (int j = 0; j < num.size(); j++){
			cout << al[i] << num[j] << "\n";
		}
	}
	return 0;
}
