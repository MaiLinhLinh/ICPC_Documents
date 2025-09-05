#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int f[n + 2]; // day con tang don dieu dai nhat den phan tu A[i]
    int pos[n + 2]; // luu chi so cua so ket thuc day con tang don dieu dai nhat truoc khi xet i;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        pos[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) { // duyet cac phan tu truoc chi so i
            if (a[i] > a[j]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1;
                    pos[i] = j;
                } else if (f[i] == f[j] + 1) {
                    if (a[j] < a[pos[i]])
                        pos[i] = j;
                }
            }
        }
    }
    int maxx = 1; // tim day con co do dai lon nhat va co thu tu tu dien nho nhat
    for (int i = 1; i <= n; i++) {
        if (f[i] > f[maxx])
            maxx = i;
        else if (f[i] == f[maxx] && a[i] < a[maxx])
            maxx = i;
    }
    stack<int> dayso;
    int ind = maxx;
    while (ind != pos[ind]) { // truy ve so bat dau la chinh no
        dayso.push(a[ind]);
        ind = pos[ind];
    }
    // sau khi ind == pos[ind]  thi while dung => ind la chi so cua phan tu dau tien
    dayso.push(a[ind]);
    cout << *max_element(f + 1, f + n + 1) << "\n";
    while (!dayso.empty()) {
        cout << dayso.top() << " ";
        dayso.pop();
    }
    return 0;
}
