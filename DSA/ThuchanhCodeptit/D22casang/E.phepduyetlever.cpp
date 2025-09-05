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
void levelOrder(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = NULL;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            insert(root, x);
        }
        levelOrder(root);
        cout << "\n";
    }

    return 0;
}
