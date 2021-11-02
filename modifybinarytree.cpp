#include<bits/stdc++.h>
using namespace std;
#define pi pair<node*,int>

struct node{
    int val;
    node *left,*right;
    node(int v):val(v),left(NULL),right(NULL){}
};
node *end;
node* modify(node* root){
    node *rightMost = root,*right = root->right;
    if(root->left){
        rightMost = modify(root->left);
        root->right = root->left;
        root->left = NULL;
    }
    if(!right)
        return rightMost;
    rightMost->right = right;
    rightMost = modify(right);
    return rightMost;
}
void preorder(node *root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->right);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node *root = new node(arr[0]);
    queue<pi> q;
    q.push({root,0});
    while(!q.empty()){
        node *curr = q.front().first;
        int i = q.front().second;
        q.pop();
        if(2*i+1 < n && arr[2*i+1]!=-1){
            curr->left = new node(arr[2*i+1]);
            q.push({curr->left,2*i+1});
        }
        if(2*i+2 < n && arr[2*i+2]){
            curr->right = new node(arr[2*i+2]);
            q.push({curr->right,2*i+2});
        }
    }
    modify(root);
    preorder(root);
}