#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+7)
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<string> s;
		s.push_back("0");
		s.push_back("1");
		for (int i = 2; i <= n; i++){
			for( int j = s.size() - 1; j>= 0; j--){
				s.push_back("1" + s[j]);
				s[j] = "0" + s[j];
			}
		}
		for (auto x: s)
			cout << x << " ";
		cout << "\n";
	}
}
