#include <iostream>
#include <math.h>
using namespace std;
int n, check;
int a[100];

void sinh()
{
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i + 1])
        i--;
    if (i == 0)
        check = 0;
    else {
        int j = n;
        while (j >= i && a[j] < a[i])
            j--;
        swap(a[i], a[j]);
        int l = i + 1, r = n;
        while (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
}
void in()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    check = 1;
    for (int i = 1; i <= 5; i++) {
        sinh();
        in();
    }
    return 0;
}
