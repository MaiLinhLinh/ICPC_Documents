#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e5 + 7)
/*
Một khu du lịch có n hòn đảo, hòn đảo i có độ cao h_i. Để di chuyển từ hòn đảo i đến hòn đảo j, du khách có thể sử dụng tàu lượn với chi phí mà max(0, hj-hi). Tuy nhiên, sau một thời gian cho thuê tàu lượn, các nhà thầu đã áp giá cho đảo thứ i là pi, di chuyển từ i đến j chi phí max(pi, hj -hi).
Tìm hành trình di chuyển từ đảo 1 đến các đảo còn lại và quay về đảo 1 với tổng chi phí min
*/
/*
max(a,b) = a + max(0, b - a);
đặt thứ tự duyệt chiều cao tăng dần sẽ làm cho chênh lệch hj - hi là min.
tong max(pi, hj - hi) = tổng pi + tổng max(0, hj-hi-pi).

*/
ll h[nmax], p[nmax];
bool cmp(int a, int b)
{
    return h[a] < h[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> p[i];
    }
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[i] = i + 1;

    // sort các đảo theo h[idx[i]] tăng dần
    sort(idx.begin(), idx.end(), cmp);

    // tinh tổng p[i]
    ll sum_p = 0;
    for (int i = 1; i <= n; i++)
        sum_p += p[i];

    // tinh tong max(0, h[j] - h[i] - p[i]);
    // tìm điểm bắt đầu là vị trí đảo 1 trong mảng idx sau sort
    int pos = find(idx.begin(), idx.end(), 1) - idx.begin();
    ll penaty = 0;
    // duyệt qua n cạnh trong chu trình
    for (int k = 0; k < n; k++) {
        // (pos + k) % n là xoay vòng vị trí trong mảng
        int u = idx[(pos + k) % n]; // u là vị trí đầu của cạnh
        int v = idx[(pos + k + 1) % n]; // v là vị trí cuối của cạnh
        if (h[v] - h[u] - p[u] > 0)
            penaty += h[v] - h[u] - p[u];
    }
    cout << sum_p + penaty << "\n";
    return 0;
}
