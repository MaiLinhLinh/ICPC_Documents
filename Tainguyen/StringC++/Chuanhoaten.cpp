// Theo quy tắc viết tiếng Anh, họ tên thường sẽ được viết lại theo chuẩn trong đó họ được viết sau cùng, phân tách với phần tên đệm và tên bởi dấu phẩy.

// Các chữ cái của phần họ đều viết hoa, còn lại thì viết hoa chữ cái đầu tiên, cách nhau bởi 1 dấu cách và không thừa dấu cách ở đầu và cuối.

// Ví dụ: " nGUYEn NHu anh" sau khi chuẩn hóa sẽ thành "Nhu Anh, NGUYEN".

#include <bits/stdc++.h>
#include <vector>
using namespace std;
void viethoa(string& s)
{
    int x = s.length();
    for (int i = 0; i < x; i++)
        s[i] = toupper(s[i]);
    return;
}
void chuanhoa(string& s)
{
    int x = s.length();
    s[0] = toupper(s[0]);
    for (int i = 1; i < x; i++) {
        s[i] = tolower(s[i]);
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> v;
        string tmp;
        while (ss >> tmp)
            v.push_back(tmp);
        viethoa(v.front());
        for (int i = 1; i < v.size() - 1; i++) {
            chuanhoa(v[i]);
            cout << v[i] << " ";
        }
        chuanhoa(v.back());
        cout << v.back() << "," << " " << v.front() << "\n";
    }
}