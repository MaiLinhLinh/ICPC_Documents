#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dem = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        for (int j = i + 1; j < s.size() - 1; j++) {
            for (int k = j + 1; k < s.size(); k++) {
                if ((j - i) != (k - j) && s[i] != s[j] && s[i] != s[k] && s[k] != s[j])
                    dem++;
            }
        }
    }
    cout << dem;
    return 0;
}
