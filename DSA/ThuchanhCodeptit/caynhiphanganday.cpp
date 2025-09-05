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
int n;
int a[10005];
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void insert(Node*& root, int i)
{
    if (i > n)
        return;
    root = new Node(a[i]);
    insert(root->left, i * 2); // con trai
    insert(root->right, i * 2 + 1);
}
void inOrder(Node* root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// duyet postOrder ko tao cay
void postOrder(int i)
{
    if (i > n)
        return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    cout << a[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        postOrder(1);
        cout << "\n";
    }

    return 0;
}
