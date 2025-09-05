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
dung bfs bien doi nguoc tu m ve n
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int step = 0;
    while (m > n) {
        if (m % 2 == 0)
            m /= 2;
        else
            m += 1; // nguoc voi phep bien doi tu n den m la n - 1
        step++;
    }
    cout << step + (n - m) << "\n";
    // khi m < n roi thi chi co the lay n tru 1 ve m
    return 0;
}
