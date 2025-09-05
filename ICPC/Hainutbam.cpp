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
const int INF = 1e9;
/*
Hôm nay, thầy giáo của Bờm đã giao cho cậu một câu đố khá thú vị với nội dung như sau:

Đầu tiên, thầy sẽ viết lên bảng 2 số nguyên dương n và m, rồi sau đó yêu cầu cậu biến đổi số n thành số m chỉ bằng hai loại thao tác là nhân số n với 2 hoặc trừ số n đi 1 đơn vị. Để bài toán trở nên hóc búa hơn, thầy yêu cầu cậu phải sử dụng ít thao tác nhất có thể.

Yêu cầu: các bạn hãy tính xem số thao tác ít nhất Bờm cần sử dụng là bao nhiêu nhé!
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {số thao tác, kết quả}
    int d[nmax] = {0};
    pq.push({ 0, n });
    d[n] = 0;
    while (!pq.empty()) {
        auto [step, num] = pq.top();
        pq.pop();
        if (step > d[num])
            continue;
        if (num == m) {
            cout << step << "\n";
            break;
        }
        if (num - 1 >= 0) {
            pq.push({ step + 1, num - 1 });
            d[num - 1] = step + 1;
        }
        if (num * 2 < 1e6 + 7) {
            pq.push({ step + 1, num * 2 });
            d[num * 2] = step + 1;
        }
    }

    return 0;
}
