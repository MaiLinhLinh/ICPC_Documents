#include <bits/stdc++.h>
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)
using namespace std;
int Partition(int a[], int l, int r)
{ // phan hoach doan l den r, tra ve vi tri chot
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i; // vi tri pivot
}
void quicksort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int q = Partition(a, l, r);
    quicksort(a, l, q - 1); // nua trai
    quicksort(a, q + 1, r); // nua phai
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
