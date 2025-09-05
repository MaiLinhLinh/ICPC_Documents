#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e9+7)
 
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (cin >> s)
		cin.ignore();
		if (s == ".")
			return 0;
		vector< string> v;
		string c;
		getline(cin, c);
		int m = c.size() - 1;
		c[m] = ' ';
		for ( int i = 0; i < m; i++)
			if (c[i] == ',')
				c[i] = ' ';
		for (auto x: c)
			cout << x;
		cout << "\n";
//		string stream ss;
//		string word;
//		while ( ss)
		
	
}