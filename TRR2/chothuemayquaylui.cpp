#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
vector<int> a(50, 0);
vector<vector<int>> ans;
int day, guest;
int c[50][50];
vector<int> visitedguest(50);
vector<int> visitedday(50);
int res = 0;
// kiem tra khack thu i co the cho thue khong
bool check(int i)
{
    for (int j = 1; j <= day; j++) {
        // neu nhu khach muon thue ngay j ma ngay j da co nguoi thue roi thi khach i khong the cho thue
        if (c[i][j] == 1 && visitedday[j]) {
            return false;
        }
    }
    return true;
}
void Try(int i, int rented)
{
    if (i > guest) {
        if (rented > res) {
            res = rented;
            ans.clear();
            ans.push_back(a);
        } else if (rented == res)
            ans.push_back(a);
        return;
    }
    // neu khong chon khach i
    a[i] = 0;
    Try(i + 1, rented);
    // neu chon khach i
    a[i] = 1;

    if (check(i)) {
        for (int j = 1; j <= day; j++) {
            if (c[i][j] == 1) {
                visitedday[j] = 1;
                rented++;
            }
        }
        Try(i + 1, rented);
        // backtrack
        for (int j = 1; j <= day; j++) {
            if (c[i][j] == 1) {
                visitedday[j] = 0;
                rented--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> guest >> day;
    for (int i = 1; i <= guest; i++) {
        for (int j = 1; j <= day; j++)
            cin >> c[i][j];
    }
    Try(1, 0);
    for (int i = 1; i <= guest; i++)
        cout << a[i] << " ";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 1; j <= guest; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
