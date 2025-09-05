// Còn 3 ngày nữa là đến hạn nộp tiểu luận nhưng Ailed chưa kịp làm gì cả. Vì nộp muộn sẽ mang lại những hậu quả rất to lớn, Ailed đã đưa ra một quyết định táo bạo.

// Ailed quyết định đi làm theo một đoạn bài báo ở trên mạng. Ailed đã quyết định lấy y hệt và chỉ đổi những chỗ có tên tác giả thành tên mình (biết tên tác giả không bao gồm khoảng trống). Để thuận tiện cho việc chỉnh sửa, Ailed quyết định đánh dấu những vị trí của tên tác giả trong đoạn.

// Input
// Dòng đầu tiên gồm 1 số nguyên dương t
//  là số bộ test (1≤t≤10)
// .

// t
//  bộ test, mỗi bộ test gồm 2 dòng:

// - Dòng đầu gồm 1 xâu X
//  là tên tác giả (1≤X.size()≤10)
// .

// - Dòng tiếp theo gồm 1 xâu S
//  là đoạn báo (1≤S.size()≤105)
// .

// Output
// Mỗi test trên 1 dòng gồm một dãy các số nguyên gồm các vị trí của tên tác giả trong đoạn, các số cách nhau bởi một dấu khảng trống. Nếu trong đoạn không có tên tác giả, in ra −1
// .
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        int idx = 1;
        int cnt = 0;
        while (ss >> word) {
            if (word == a) {
                cout << idx << " ";
                cnt++;
            }
            idx += (word.size() + 1);
        }
        if (cnt == 0)
            cout << "-1";
        cout << "\n";
    }
}