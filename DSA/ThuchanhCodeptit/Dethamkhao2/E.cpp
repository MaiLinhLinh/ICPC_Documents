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
// xay cay theo muc tu trai sang phai co NULL
void insert(Node*& root, string s)
{
    stringstream ss(s);
    string x;
    vector<string> v;
    while (ss >> x) {
        v.push_back(x);
    }
    if (s[0] == 'N')
        return;
    root = new Node(stoi(v[0]));
    int i = 1;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        // them contrai
        if (i < v.size() && v[i] != "N") {
            current->left = new Node(stoi(v[i]));
            q.push(current->left);
        }
        i++;
        // them con phai
        if (i < v.size() && v[i] != "N") {
            current->right = new Node(stoi(v[i]));
            q.push(current->right);
        }
        i++;
    }
}
void RNL(Node* root)
{
    if (root == NULL)
        return;
    RNL(root->right);
    cout << root->data << " ";
    RNL(root->left);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = NULL;
        insert(root, s);
        RNL(root);
        cout << "\n";
    }

    return 0;
}
