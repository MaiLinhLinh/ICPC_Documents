#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;
string s;
int check;
void sinh (){
	int i = s.size() - 2;
	while (i >= 0 && s[i] >= s[i+1])
		--i;
	if (i == -1)
		check = 0;
	else{
		int j = s.size() - 1;
		while (j >= i && s[j] <= s[i])
			--j;
		swap(s[i], s[j]);
		int l = i + 1, r = s.size()	- 1;
		while (l <= r){
			swap(s[l], s[r]);
			l++;
			r--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int thtu;
	for (int i = 1; i <= t; i++){
		cin >> thtu >> s;
		cout << i << " ";
		check = 1;
		sinh();
		if (check == 0)
			cout << "BIGGEST\n";
		else{
			cout << s << "\n";
		}
	}
}
