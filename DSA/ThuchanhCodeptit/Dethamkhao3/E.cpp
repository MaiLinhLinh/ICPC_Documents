#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// chen 1 not co gia tri x len cay nhi phan tim kiem
void insert(Node* & root, int x){
    if(root == NULL){
        root = new Node(x);
        return;
    }
    if(x < root -> data)
        insert(root -> left, x);
    else if( x > root -> data)
        insert(root -> right, x);
}
// tim node la ben phai
Node* findMax(Node* root){
    while(root && root -> right != NULL){
        root = root -> right;
    }
    return root;
}

// tim node la ben trai
Node* findMin(Node * root){
    while(root && root -> left != NULL)
        root = root -> left;
    return root;
}

// xoa di 1 not co gia tri x tren cay nhi phan tim kiem
void removeNode(Node *& root, int x){
    if(root == NULL)
        return;
    if(x < root -> data)
        removeNode(root->left, x);
    else if(x > root -> data)
        removeNode(root -> right, x);
    else{
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            root = NULL;
        }
        else if(root-> left == NULL){
            // chi co con phai, thi xoa node do, con phai len thay vi tri
            Node * p = root;
            root = root -> right;
            delete p;
        }else if(root -> right == NULL){
            Node * p = root;
            root = root -> left;
            delete p;
        }
        else{
            // co ca 2 con
            // tim node nhỏ nhat cua cay con ben phai(tuc di tim node la trai cua cay con phai)
            Node* maxNode = findMin(root->right);
            root ->data = maxNode -> data;
            removeNode(root ->right, maxNode->data);
        }
    }
}
void preOrder(Node * root){
    if(root == NULL)
        return;
    cout << root ->data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    Node * root = NULL;
    for(int i = 1; i <= q; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s == "ins"){
            insert(root, x);
        }
        else if(s == "del"){
            removeNode(root,x);
        }
        cout << "Query #" << i << ": ";
        preOrder(root);
        cout << "\n";
    }

}
