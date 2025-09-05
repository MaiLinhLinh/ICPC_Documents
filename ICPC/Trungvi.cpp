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
Trung vị: N chẵn là phần tử nhỏ thứ N/2, N lẻ là trung bình 2 phần tử giữa mảng (đã sort)
*/
double median2D(const vector<vector<int>>& a) {
    vector<int> v;
    for (auto &row : a) v.insert(v.end(), row.begin(), row.end());
    int N = (int)v.size();
    int k = N/2;

    nth_element(v.begin(), v.begin()+k, v.end());
    if (N % 2 == 1) return v[k];

    int m2 = v[k];
    nth_element(v.begin(), v.begin()+k-1, v.end());
    int m1 = v[k-1];
    return (m1 + m2) / 2.0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
