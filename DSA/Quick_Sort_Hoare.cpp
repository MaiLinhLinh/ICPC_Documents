#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int Partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (1) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            --j;
        if (i < j) {
            swap(a[i], a[j]); // doi vi tri
            i++; // tang vi tri xet
            j--; // j hien tai da xet, nen can giam j
        } else
            return j; // pivot
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
