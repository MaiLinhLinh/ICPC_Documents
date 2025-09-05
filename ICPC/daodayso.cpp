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
/* ý tưởng: số thứ tự lẻ thì đẩy vào đầu, số thứ tự chẵn thì đẩy vào cuối. dùng deque*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            dq.push_front(a[i]);
        } else
            dq.push_back(a[i]);
    }
    if (n % 2) {
        while (!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    } else {
        while (!dq.empty()) {
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    return 0;
}
