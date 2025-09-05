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

    vector<int> r;
    vector<int> b;
    vector<int> g;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R')
            r.push_back(i);
        else if (s[i] == 'B')
            b.push_back(i);
        else if (s[i] == 'G')
            g.push_back(i);
    }
    int dem = 0;
    for (auto i : r) {
        for (auto j : b) {
            for (auto k : g) {
                if ((i < j && j < k)) {
                    if (abs(j - i) != abs(k - j))
                        dem++;
                }
                if ((i < k && k < j)) {
                    if (abs(k - i) != abs(k - j))
                        dem++;
                }
                if ((j < i && i < k)) {
                    if (abs(j - i) != abs(k - i))
                        dem++;
                }
                if ((j < k && k < i)) {
                    if (abs(j - k) != abs(k - i))
                        dem++;
                }
                if ((k < j && j < i)) {
                    if (abs(j - k) != abs(i - j))
                        dem++;
                }
                if ((k < i && i < j)) {
                    if (abs(k - i) != abs(i - j))
                        dem++;
                }
            }
        }
    }

    cout << dem;
    return 0;
}
