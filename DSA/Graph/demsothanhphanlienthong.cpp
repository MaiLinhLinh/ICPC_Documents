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
    int cnt = 0;
    int đỉnh, cạnh;
    for (int i = 1; i <= đỉnh; i++) {
        // neu dinh chưa được duyệt
        cnt++;
        bfs(i) hoặc dfs(i); // duyệt thành phần liên thông của i.
    }
    cout << cnt;
    return 0;
}
