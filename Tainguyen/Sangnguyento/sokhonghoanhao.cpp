// Một số hoàn hảo nếu nó bằng tổng các ước nhỏ hơn nó.

// Ví dụ 28 là một số hoàn hảo vì 28 = 1 + 2 + 4 + 7 + 14.

// Ta gọi đại lượng F(N)
//  đặc trưng cho sự không hoàn hảo của một số. F(N)
//  bằng hiệu giữa N
//  và các ước của N
//  nhỏ hơn nó. Như vậy với một số hoàn hảo N
// , F(N)
//  =
//  0.

// Nhiệm vụ của bạn là hãy viết một chương trình tính tổng F(A)+F(A+1)+…+F(B)
//  với A
// , B
//  cho trước.

#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7)
using namespace std;
vector<int> Prime;
bool p[nmax];
void Eratosthenes()
{
    p[0] = p[1] = true;
    for (int i = 2; i * i <= nmax; i++) {
        if (!p[i]) {
            for (int j = i * i; j <= nmax; j += i)
                p[j] = true;
        }
    }
    for (int i = 2; i <= nmax; i++)
        if (p[i] == false)
            Prime.push_back(i);
}
ll sumdiv(int n)
{
    int m = n;
    ll sum = 1;
    for (int i = 0; Prime[i] * Prime[i] <= n; i++) {
        int d = Prime[i];
        int k = 0;
        while (n % Prime[i] == 0) {
            d *= Prime[i];
            k++;
            n /= Prime[i];
        }
        if (k > 0)
            sum *= (d - 1) / (Prime[i] - 1);
    }
    if (n > 1)
        sum *= (n + 1);
    return abs(m - (sum - m));
}
ll pre[nmax];
int main()
{
    Eratosthenes();
    pre[0] = 0;
    pre[1] = 1;
    for (int i = 2; i <= nmax; i++) {
        pre[i] = pre[i - 1] + sumdiv(i);
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }
}