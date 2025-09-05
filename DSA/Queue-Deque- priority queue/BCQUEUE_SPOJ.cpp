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
    queue<int> q;
    while (n--) {
        int x;
        cin >> x;
        if (x == 1)
            cout << q.size() << "\n";
        else if (x == 2) {
            if (q.empty())
                cout << "YES\n";
            else
                cout << "NO\n";
        } else if (x == 3) {
            int m;
            cin >> m;
            q.push(m);
        } else if (x == 4) {
            if (!q.empty())
                q.pop();
        } else if (x == 5) {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        } else if (x == 6) {
            if (q.empty())
                cout << "-1\n";
            else {
                queue<int> p = q;
                while (p.size() != 1)
                    p.pop();
                cout << p.front() << "\n";
            }
        }
    }
    return 0;
}
