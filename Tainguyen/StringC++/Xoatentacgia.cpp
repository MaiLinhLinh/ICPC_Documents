#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        vector<string> v;
        int cnt = 0;
        while (ss >> word) {
            if (word != a)
                v.push_back(word);
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }
}