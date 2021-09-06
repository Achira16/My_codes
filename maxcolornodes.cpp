#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int func(vector<int>& par,vector<int>& A,vector<int>& B,vector<int>& C,int n,int m)
{
    for(int i=0;i<n;i++)
        par[i]--;
    vector<pi> cost(n);
    for(int i=0;i<n;i++)
    {
        cost[i] = {A[i],i};
    }
    sort(cost.begin(),cost.end());
    vector<int> des_colored(n,0);
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int node = cost[i].second,c = cost[i].first;
        if(des_colored[node] >= C[node] && B[node] < c)
        {
            if(B[node] <= m)
            {
                m-=B[node];
                count++;
                int p = par[node];
                while(p != -2)
                {
                    cout<<p;
                    des_colored[p]++;
                    p = par[p];
                }
            }
        }
        else if(c <= m)
        {
            m-=c;
            count++;
            int p = par[node];
            while(p != -2)
            {
                des_colored[p]++;
                p = par[p];
            }
        }
    }
    return count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        cin>>parent[i];
    }
    vector<int> A(n),B(n),C(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    for(int i=0;i<n;i++)
        cin>>C[i];
    for(int i=0;i<n;i++)
        parent[i]--;
    cout<<func(parent,A,B,C,n,m);
}