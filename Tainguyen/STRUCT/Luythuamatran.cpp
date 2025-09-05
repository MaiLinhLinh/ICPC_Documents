// Cho ma trận vuông A kích thước N∗N
// . Nhiệm vụ của bạn là hãy tính ma trận X=AK
// //  với K là số nguyên cho trước. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int mod = 1e9 + 7;

struct MaTran {
    ll a[12][12];

    void nhap()
    {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        }
    }

    void in()
    {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
};

MaTran nhan(MaTran A, MaTran B)
{
    MaTran res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res.a[i][j] = 0;
            for (int k = 0; k < n; ++k)
                (res.a[i][j] += (A.a[i][k] * B.a[k][j]) % mod) %= mod;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        MaTran A;
        A.nhap();
        MaTran tmp = A;
        for (int i = 1; i < k; ++i)
            A = nhan(A, tmp);
        A.in();
    }
}