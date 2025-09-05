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
void insert(Node*& root, int x)
{
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (x > root->data)
        insert(root->right, x);
    else if (x < root->data)
        insert(root->left, x);
}

void postOrder(Node* root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        int n;
        cin >> n;
        Node* root = NULL;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            insert(root, x);
        }
        cout << "Test #" << j << ": ";
        postOrder(root);
        cout << "\n";
    }

    return 0;
}
