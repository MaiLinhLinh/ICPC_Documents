#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
/*
Lớp học Cấu trúc dữ liệu & giải thuật có N sinh viên, trong đó có một số nhóm sinh viên chơi thân với nhau. Nếu X và Y là bạn, Y và Z là bạn, theo tính chất bắc cầu, X và Z cũng là bạn.

Để tránh việc trao đổi bài, các thầy cô đã sắp xếp phòng thi cho các bạn sinh viên sao cho không có bất kì 2 sinh viên nào là bạn của nhau ở cùng một phòng. Các bạn hãy thử tính xem các thầy cô cần sử dụng ít nhất bao nhiêu phòng thi?

Ý tưởng: DSU => tính thành phần liên thông dài nhất => số đỉnh thuộc tplt này là số phòng ít nhất
*/
class DSU {
public:
    int N;
    vector<int> parent, num;

    DSU(int N)
    {
        this->N = N;
        parent.reserve(N + 1);
        num.resize(N + 1, 1);
        for (int i = 1; i <= N; i++)
            parent[i] = i;
    }

    int findSet(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findSet(parent[u]);
    }

    void unionSet(int u, int v)
    {
        int a = findSet(u);
        int b = findSet(v);
        if (a == b)
            return;
        if (num[a] < num[b])
            swap(a, b);
        num[a] += num[b];
        parent[b] = a;
    }

    int getSize(int u)
    {
        return num[findSet(u)];
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu = DSU(n);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unionSet(x, y);
    }
    int maxx = 1;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, dsu.getSize(i));
    }
    cout << maxx << "\n";
    return 0;
}
