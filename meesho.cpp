#include<bits/stdc++.h>
using namespace std;
#define ll long long

class UnionFind{
    vector<int> dsuf;
    public:
    UnionFind(int n){
        dsuf.resize(n+1);
        iota(dsuf.begin(),dsuf.end(),0);
    }
    int connect(int a,int b){
        int p = find(a),q = find(b);
        if(p < q)
            dsuf[p] = q;
        else
            dsuf[q] = p;
        return max(p,q);
    }
    int find(int a){
        return dsuf[a] == a ? a : dsuf[a] = find(dsuf[a]);
    }
    bool connected(int a,int b){
        return find(a) == find(b);
    }
};

vector<ll> func(ll c_nodes,int c_edges,vector<int>& c_from,vector<int>& c_to){
    unordered_set<int> parents;
    vector<ll> ans;
    UnionFind obj(c_nodes);
    ll sum = (c_nodes*(c_nodes+1))/2;
    for(int i=0;i<c_edges;i++){
        if(!obj.connected(c_from[i],c_to[i])){
            int p = obj.find(c_from[i]),q = obj.find(c_to[i]);
            sum = sum-p-q+obj.connect(c_from[i],c_to[i]);
        }
        ans.push_back(sum);
    }
    return ans;
}
int main(){
    int c_nodes,c_edges;
    cin>>c_nodes>>c_edges;
    vector<int> c_from(c_edges),c_to(c_edges);
    for(int i=0;i<c_edges;i++) cin>>c_from[i];
    for(int i=0;i<c_edges;i++) cin>>c_to[i];
    vector<ll> res = func(c_nodes,c_edges,c_from,c_to);
    for(ll i:res) cout<<i<<" ";
}