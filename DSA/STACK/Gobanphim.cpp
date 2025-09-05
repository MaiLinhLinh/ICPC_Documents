#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
// ytuong: stack left, luu cac ki tu ben trai con tro, stack right luu cac ki tu ben phai con tro
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    stack<char> left;
    stack<char> right;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) // nhap ki tu vao thi luon o ben trai con tro
            left.push(s[i]);
        else if (s[i] == '-' && !left.empty()) // xoa 1 ki tu ben trai con tro
            left.pop();
        else if (s[i] == '<' && !left.empty()) { // con tro dich sang trai=> 1 ki tu ben trai con tro tro thanh ben phai con tro
            right.push(left.top());
            left.pop();
        } else if (s[i] == '>' && !right.empty()) { // con tro dich sang phai => 1 ki tu ben phai con tro tro thanh ben trai con tro
            left.push(right.top());
            right.pop();
        }
    }
    // left in xuoi stack, right in nguoc stack
    string tmp = "";
    while (!left.empty()) {
        tmp += left.top();
        left.pop();
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp;
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}
