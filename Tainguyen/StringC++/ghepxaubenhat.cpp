Xu đang học về chuỗi kí tự, và đặc biệt Xu thích sắp xếp các chuỗi theo một thứ tự nào đó.Hôm nay cô giáo ra cho Xu một bài toán khá mới lạ :

    Cho N xâu kí tự.Nhiệm vụ là hãy ghép các xâu này thành một từ,
    sao cho từ thu được có thứ tự từ điển nhỏ nhất.

// Xu cảm thấy rất mới và khó, các bạn hãy giúp Xu giải bài toán này nhé.
#include <bits/stdc++.h>
    using namespace std;
bool cmp(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string c;
            cin >> c;
            v.push_back(c);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
            cout << v[i];
        cout << "\n";
    }
}