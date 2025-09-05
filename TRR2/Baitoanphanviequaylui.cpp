#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int nguoi, viec;
int c[100][100];
int res = 1e9;
vector<vector<int>> ans;
vector<int> a(50);
int visited[1000];
void Try(int i, int sum)
{
    if (i > viec) {

        if (sum < res) {
            res = sum;
            ans.clear();
            ans.push_back(a);
        } else if (sum == res) {
            ans.push_back(a);
        }
    }
    for (int j = 1; j <= viec; j++) {
        if (!visited[j]) {
            a[i] = j;
            visited[j] = 1;
            sum += c[i][a[i]];
            Try(i + 1, sum);
            visited[j] = 0;
            sum -= c[i][a[i]];
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    nguoi = viec = n;
    for (int i = 1; i <= nguoi; i++) {
        for (int j = 1; j <= viec; j++)
            cin >> c[i][j];
    }
    Try(1, 0);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 1; j <= viec; j++) {
            printf("Man%d->Job%d || ", j, ans[i][j]);
        }
        cout << "\n";
    }
    return 0;
}
