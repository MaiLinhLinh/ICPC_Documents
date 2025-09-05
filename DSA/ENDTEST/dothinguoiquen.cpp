// Sự thật ít ai biết, khúc kết phim 'Hôn lễ của em', Châu Tiêu Tề không rời khỏi đám cưới của Vưu Vịnh Từ ngay mà sau đó anh trở lại để giúp cô một việc.

// Đám cưới của cô có n
//  khách mời, từ thông tin của người quen cô có được danh sách m
//  cặp số (u,v)
//  các mối quan hệ giữa các khách mời. Với mỗi 1
//  cặp (u,v)
//  cho biết khách mời u
//  có quen biết với khách mời v
//  và ngược lại.

// Sau lễ cưới, cô sẽ tổ chức một buổi tiệc nho nhỏ chỉ dành cho những người quen. Những người tham dự phải quen ít nhất k người khác (chỉ tính những người trong buổi tiệc) và số lượng khách mời là nhiều nhất có thể.

// Nhưng hiện tại cô đang trên lễ đường rồi, nên cô đưa danh sách cho Châu Tiêu Tề và nhờ anh giúp. Tuy nhiên số lượng khách mời quá nhiều, các bạn D23 hãy giúp anh ấy nhé!
// 5 7 2
// 4 3
// 1 2
// 4 1
// 1 3
// 3 2
// 2 4
// 5 4
// Output
// 4
// 1 2 3 4
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<int> in_party;
    for (int i = 1; i <= n; i++)
        in_party.insert(i);

    while (true) {
        vector<int> remove;
        for (int u : in_party) {
            int cnt = 0;
            for (int v : adj[u])
                if (in_party.count(v))
                    cnt++;
            if (cnt < k)
                remove.push_back(u);
        }

        if (remove.empty())
            break;
        else
            for (int u : remove)
                in_party.erase(u);
    }

    cout << in_party.size() << endl;
    for (int x : in_party)
        cout << x << ' ';

    return 0;
}