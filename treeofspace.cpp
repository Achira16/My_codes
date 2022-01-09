#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pi pair<node*,int>

struct node
{
    string val;
    node *parent;
    bool locked;
    int id;
    unordered_set<node*> locked_desc;
    node(string v):val(v),parent(nullptr),id(-1),locked(0){}
    node(string v,node *par):val(v),parent(par),id(-1),locked(0){}
};

bool lock(node* root,int uid){
    if(root->locked || root->locked_desc.size() > 0) return 0;
    node *par = root->parent;
    while(par){
        if(par->locked) return 0;
        par = par->parent;
    }
    root->locked = 1;
    root->id = uid;
    par = root->parent;
    while(par){
        par->locked_desc.insert(root);
        par = par->parent;
    }
    return 1;
}

bool unlock(node* root,int uid){
    if(!root->locked || root->id != uid) return 0;
    root->locked = 0;
    root->id = -1;
    node *par = root->parent;
    while(par){
        par->locked_desc.erase(root);
        par = par->parent;
    }
    return 1;
}

bool upgrade(node* root,int uid){
    if(root->locked || root->locked_desc.size() == 0) return 0;
    for(auto child:root->locked_desc){
        if(child->id != uid) return 0;
    }
    unordered_set<node*> temp = root->locked_desc;
    for(auto child:temp){
        unlock(child,uid);
    }
    lock(root,uid);
    return 1;
}
int main(){
    IOS;
    int N,m,Q;
    cin>>N>>m>>Q;
    unordered_map<string,node*> tree;
    string s;
    cin>>s;
    int count = 1;
    node *root = new node(s);
    queue<node*> q;
    q.push(root);
    tree[s] = root;
    while(!q.empty() && count<N){
        node *par = q.front();
        q.pop();
        int n = N-count;
        if(n >= m){
            for(int i=0;i<m;i++){
                cin>>s;
                count++;
                tree[s] = new node(s,par);
                q.push(tree[s]);
            }
        }
        else{
            for(int i=0;i<n;i++){
                cin>>s;
                count++;
                tree[s] = new node(s,par);
                q.push(tree[s]);
            }
        }
    }
    string val;
    int op,uid;
    while(Q--){
        cin>>op>>val>>uid;
        if(op == 1){
            cout<<lock(tree[val],uid)<<endl;
        }
        else if(op == 2){
            cout<<unlock(tree[val],uid)<<endl;
        }
        else{
            cout<<upgrade(tree[val],uid)<<endl;
        }
    }
}