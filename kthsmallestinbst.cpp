#include<bits/stdc++.h>
using namespace std;

struct node{
    int val,lcount,rcount;
    node *left,*right;
    node(): val(0), left(NULL), right(NULL), lcount(0), rcount(0){}
    node(int v):val(v), lcount(0), rcount(0), left(NULL), right(NULL){}
};

node* insert(node *root,int x){
    if(!root) return new node(x);
    if(x < root->val){
        root->left = insert(root->left,x);
        root->lcount++;
    }
    else if(x > root->val){
        root->right = insert(root->right,x);
        root->rcount++;
    }
    return root;
}
node* kthSmallest(node *root, int k){
    if(!root) return root;
    int count = root->lcount+1;
    if(k == count)
        return root;
    if(k < count)
        return kthSmallest(root->left,k);
    return kthSmallest(root->right,k-count);
}
node* kthLargest(node *root, int k){
    if(!root) return root;
    int count = root->rcount+1;
    if(k == count)
        return root;
    if(k < count)
        return kthLargest(root->right,k);
    return kthLargest(root->left,k-count);
}
int main(){
    int n,k;
    cin>>n;
    cin>>k;
    int keys[n];
    for(int i=0;i<n;i++)   
        cin>>keys[i];
    node *root;
    for(int x:keys)
        root = insert(root,x);
    node* min = kthSmallest(root,k);
    cout<<min->val<<"\n";
    node *max = kthLargest(root,k);
    cout<<max->val;
}