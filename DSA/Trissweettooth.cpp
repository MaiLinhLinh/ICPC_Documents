#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// y tuong sinh nhi phan tren 2 nua mang
// vi tri tuong ung 0 thi cong thanh sum2, vi tri tuong ung 1 thi cong thanh sum1
// vidu 1 2 / 2 3 => sinh nhi phan 2. 00 01 10 11
// s1: 0 , 2, 1, 3
// s2: 0, 3, 2, 5
// s1, s2 la mang chua tong cac vi tri 1 cua tung nhi phan sinh ra
// => s1 + s2 = sum1 ( sat voi sum/2 nhat)( lay s1 lam moc, tknp tren s2 sao cho s1 + s2 gan sum/2)
// khi do sum2 = sum - sum1 se gan vs sum/2 nhat => do chenh sum1, sum2 min
// khi sum1 + sum2 khong doi ma sum1, sum2 phai gan sum/2 nhat thi 1 trong 2 sum1, sum2, se co 1 gia tri <= sum/2, 1 tri >= sum/2
// => tim th sum1 >= sum/2 la duoc.
int v[25], n, check;
void init()
{
    for (int i = 1; i <= n; i++) {
        v[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && v[i] == 1) {
        v[i] = 0;
        --i;
    }
    if (i == 0)
        check = 0;
    else
        v[i] = 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a[n + 1], sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    n /= 2;
    vector<int> s1, s2;
    init();
    check = 1;
    while (check) {
        int sumfi = 0, sumse = 0;
        for (int i = 1; i <= n; i++) {
            sumfi += v[i] * a[i];
            sumse += v[i] * a[i + n];
        }
        s1.push_back(sumfi);
        s2.push_back(sumse);
        sinh();
    }
    sort(s2.begin(), s2.end()); // sort de dung lower bound
    int ans = INT_MAX;
    for (int i = 0; i < s1.size(); i++) {
        int p = *lower_bound(s2.begin(), s2.end(), sum / 2 - s1[i]);
        int sum1 = s1[i] + p;
        int sum2 = sum - sum1;
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans << "\n";
    return 0;
}
// 1 3 /3 3 => sum = 10 => sum /2 = 5
/*
sinh nhi phan nua mang : 00 01 10 11
s1 = 0, 3, 1 , 4 // s1 = 4 => s2 = 3=> 7 3, s1 = 0, s2 = 6 => 6, 4
s2 = 0, 3, 3, 6
=> voi moi s1[i], tim 1 so thuoc s2, de s1[i] + s2 gan sum/2 nhat
vi du s1[i] = 1 => sum/2 - s1 = 4 => lower bound se tim ra trong s2 la so 6
=> sum1 = 1 + 6 = 7, sum2 = 10 - 7 = 3 => abs(sum1 - sum2) = 4
nhung neu s1[i] = 1 nhung chon s2 la 3 => sum1 = 4, sum2 = 6, truong hop nay cx la 6 4 khi tim sum1 theo lower bound
neu tao ra dc truong hop sum1 < sum/2 thì sum2 > sum/2  vay hoan vi no thi se luon ton tai th sum1> sum/2, sum2< sum/2 ma abs nhu nhau
*/
