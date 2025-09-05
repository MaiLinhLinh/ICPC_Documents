#include<bits/stdc++.h>
#define ll long long
#define mod int(1e9+7)
#define nmax int(1e6+5)
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[5] = {0, 9, 90, 900, 9000};// tu 1 - 9 co 9 so 1 cs. tu 10 den 99 co 90 so co 2 cs,... 
	int num_digit;
	for( num_digit = 1; num_digit * a[num_digit] < n; num_digit++){
		n -= num_digit * a[num_digit];
	}
	// num_digit la xac dinh thuoc vung so bao nhieu chu so
	// vidu 210 => num_digit = 3; tuc la thuoc vung 3 chu so
	int r = n % num_digit; // ( xac dinh xem no la chu so nao)
	n /= num_digit; // xac dinh xem no la so thu may trong cac so co 3 chu so;
	n += pow(10, num_digit - 1) - 1; // tinh ra so do;
	if ( r == 0)
		r = num_digit;
		// neu r = 0, ket qua la vi tri r cua so do
	else
		n++;
	// neu r != 0, ket qua la vi tri r cua so ke tiep
	string s = to_string(n);
	cout << s[r-1] << "\n";
	
}
