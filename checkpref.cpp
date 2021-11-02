#include<bits/stdc++.h>
using namespace std;

struct node{
    vector<node*> child;
    node(){child.resize(26);}
};
void insert(string& s,node *root){
    for(int i=0;i<s.size();i++){
        if(!root->child[s[i]-'a'])
            root->child[s[i]-'a'] = new node();
        root = root->child[s[i]-'a'];
    }
}
void dfs(node* root,string& s,vector<string>& ans){
    bool flag = 0;
    for(int i=0;i<26;i++){
        if(root->child[i]){
            flag = 1;
            s.push_back(i+'a');
            dfs(root->child[i],s,ans);
            s.pop_back();
        }
    }
    if(!flag)
        ans.push_back(s);
}
int main(){
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node *root = new node();
    for(int i=0;i<n;i++)
        insert(arr[i],root);
    vector<string> ans;
    string s;
    dfs(root,s,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }
}