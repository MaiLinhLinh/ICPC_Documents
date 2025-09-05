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
Cho xâu S độ dài N và K từ trong trong từ điển. Tính số cách ghép các từ trong từ điển để tạo thành xâu S (một từ có thể sử dụng nhiều lần).
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> v;
    for (int i = 1; i <= k; i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }

    return 0;
}
