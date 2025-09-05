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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1; // cộng vào kí tự rỗng để đẩy chỉ số lên 1
    s2 = " " + s2;
    int dp[n + 1][m + 1]; // dp[i][j] là độ dài xâu con chung dài nhất
    // tính từ 1 đến chỉ số i của xâu s1(hay i kí tự đầu của s1) và j của xâu s2(j kí tự đầu của s2)
    //  BTCS
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0; // chọn i kí tự xâu s1 và 0 kí tự xâu s2
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0; // chọn 0 kí tự xâu s1 và j kí tự xâu s2
    for (int i = 1; i <= n; i++) { // duyet các kí tự trong 2 xâu
        for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) // nếu 2 kí tự bằng nhau thì độ dài xâu chung max của i-1 kí tự s1, j-1 kí tự s2 +1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else // ngược lại. đi so sánh xâu con chung max của i kí tự s1, j-1 kí tự s2(trước đó) và i-1 kí tự s1(trước đó), j kí tự s2
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
    return 0;
}
