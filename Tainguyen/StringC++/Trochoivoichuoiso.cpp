// Một nhóm bao gồm N
//  người, người thứ i có tên Si
// , vì quá buồn chán nên họ đã nghĩ ra một trò chơi như sau:

// Sẽ có Q
//  lượt quay ngẫu nhiên, mỗi lần sẽ ra một kí tự c
//  từ 'a' đến 'z', trong mỗi lượt quay mà người nào có tên chứa ít nhất 1 kí tự c
//  thì sẽ bị loại khỏi vòng chơi ở lượt đó.

// Câu hỏi đặt ra là họ không biết số người còn lại trong vòng chơi sau mỗi lượt là bao nhiêu. Bạn hãy giúp họ để kiểm soát số người trong vòng chơi nhé.
#include <bits/stdc++.h>
using namespace std;
bool checkN[100005]; // tao mang danh dau so nguoi, ai bi loai thi la 1
bool checkQ[126]; // tao mang danh dau chu cai, chi co 26 chu cai, chu cai nao nhap roi thi la 1
int main()
{
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<set<char>> v(n); // vector n phan tu, moi phan tu la 1 set
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char x : s)
            v[i].insert(x); // insert char vao set(set se loai bot chu cai trung cua ten)
    }
    int cnt = n;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (checkQ[c] == 0) { // neu chu cai nhap vao khong trung voi chu cai truoc do thi moi xet de loai nguoi choi
            checkQ[c] = 1; // danh dau chu cai da nhap
            for (int j = 0; j < n; j++) {
                if (checkN[j] == 0 && v[j].count(c) != 0) { // neu nguoi choi chua bi loai va trong ten co chua chu cai nhap vao
                    checkN[j] = 1;
                    cnt--; // thi loai nguoi do di
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}