#include <bits/stdc++.h>
using namespace std;
int thnghich(string s)
{
    int x = s.length();
    for (int i = 0; i <= x / 2; i++) {
        if (s[i] != s[x - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'C')
                s[i] = '2';
            else if (s[i] >= 'D' && s[i] <= 'F')
                s[i] = '3';
            else if (s[i] >= 'G' && s[i] <= 'I')
                s[i] = '4';
            else if (s[i] >= 'J' && s[i] <= 'L')
                s[i] = '5';
            else if (s[i] >= 'M' && s[i] <= 'O')
                s[i] = '6';
            else if (s[i] >= 'P' && s[i] <= 'S')
                s[i] = '7';
            else if (s[i] >= 'T' && s[i] <= 'V')
                s[i] = '8';
            else if (s[i] >= 'W' && s[i] <= 'Z')
                s[i] = '9';
        }
        if (thnghich(s))
            cout << "YES\n";
        else
            cout << "No\n";
    }
    return 0;
}