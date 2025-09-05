// Trong quá trình làm bài tập, bàn phím của Zin bất ngờ gặp vấn đề.

// Bây giờ, khi Zin nhấn phím b, nó hoạt động giống như một phím xóa lùi bất thường: nó xóa chữ cái viết thường cuối cùng (ngoài cùng bên phải) trong chuỗi đã gõ. Nếu không có chữ cái viết thường trong chuỗi đã gõ thì việc nhấn hoàn toàn bị bỏ qua.

// Tương tự, khi Zin nhấn phím B, nó sẽ xóa chữ in hoa cuối cùng (ngoài cùng bên phải) trong chuỗi đã gõ. Nếu không có chữ in hoa trong chuỗi gõ thì việc nhấn hoàn toàn bị bỏ qua.

// Trong cả hai trường hợp, các chữ cái b và B không được thêm vào chuỗi đã nhập khi nhấn các phím này.

// Giả sử chuỗi gõ là: "ARaBbbitBaby". Chuỗi gõ sẽ được thay đổi như sau: "" →A
//  "A" →R
//  "AR" →a
//  "ARa" →B
//  "Aa" →b
//  "A" →b
//  "A" →i
//  "Ai" →t
//  "Ait" →B
//  "it" →a
//  "ita" →b
//  "it" →y
//  "ity".

// Cho một chuỗi là các phím đã được nhấn. In ra màn mình chuỗi đã được xử lý.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int m = s.size();
        int uppercase = 0, lowercase = 0;
        string ans;
        for (int i = 0; i < m; i++) {
            if (s[i] == 'b')
                lowercase++;
            else if (s[i] == 'B')
                uppercase++;
            else if (isupper(s[i]) && uppercase > 0)
                uppercase--;
            else if (islower(s[i]) && lowercase > 0)
                lowercase--;
            else
                ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}