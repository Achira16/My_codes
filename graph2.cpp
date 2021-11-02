#include<bits/stdc++.h>
using namespace std;

template<int N> 
struct S{
    enum{
        value = S<N/2>::value+(N%2)
    };
};
template<>
struct S<0>{
    enum{
        value = 0
    };
};
void dfs(int i,int par,vector<vector<int>>& graph,vector<bool>& vis,int& ans){
    vis[i] = 1;
    for(auto j:graph[i]){
        if(j!=par)
            ans = max(ans,(int)graph[i].size()+(int)graph[j].size()-1);
        if(!vis[j])
            dfs(j,i,graph,vis,ans);
    }
}
int Solution(vector<int>& A,vector<int>& B,int N){
    vector<vector<int>> graph(N+1);
    for(int i=0;i<A.size();i++){
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }
    vector<bool> vis(N+1);
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(!vis[i])
            dfs(i,-1,graph,vis,ans);
    }
    return ans;
}
int main(){
    // int n,m;
    // cin>>n>>m;
    // vector<int> A(m),B(m);
    // for(int i=0;i<m;i++)
    //     cin>>A[i];
    // for(int i=0;i<m;i++)
    //     cin>>B[i];
    // cout<<func(A,B,n);
    cout<<S<10>::value;
    int x;
    cout<<x+1;
}