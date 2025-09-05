//
#include <bits/stdc++.h>
#define ll long long
#define nmax int(1e6 + 7)
using namespace std;
bool prime[nmax];
void sang()
{
    prime[0] = prime[1] = true;
    for (int i = 2; i * i <= nmax; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= nmax; j += i)
                prime[j] = true;
        }
    }
}
int main()
{
    sang();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = n;; i++) {
            if (!prime[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
}