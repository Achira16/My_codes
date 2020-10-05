#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int N = 26;
vector<vector<int>> graph(N);
vector<string> s(30);
bool cycle,vis[26],recstack[26];
vector<int> ans;
void dfs(int u)
{
    vis[u] = true;
    recstack[u] = true;
    for(int v:graph[u])
    {
        if(recstack[v] && v^u)
            cycle = true;
        else if(!vis[v])
            dfs(v);
    }
    ans.push_back(u);
    recstack[u] = false;
}
int main()
{
    IOS;
    int t,r,c;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>r>>c;
        set<char> st;
        for(int j=0;j<r;j++)
        {
            cin>>s[j];
            for(char x:s[j])
                st.insert(x);
            if(j)
            {
                for(int k=0;k<c;k++)
                {
                    
                    graph[s[j][k]-'A'].push_back(s[j-1][k]-'A');
                    
                }
            }
        }
       /* for(char ch:st)
        {
            cout<<ch<<"->";
            for(int v:graph[ch-'A'])
            {
                cout<<(char)(v+'A')<<"->";
            }
            cout<<endl;
        }*/
        ans.clear();
        cycle = false;
        memset(vis,0,sizeof(vis));
        memset(recstack,0,sizeof(recstack));
        cout<<"Case #"<<i<<": ";
        for(char ch:st)
        {
            if(!vis[ch-'A'])
                dfs(ch-'A');
        }
        if(cycle)
            cout<<-1<<endl;
        else
        {
            for(auto it=ans.rbegin();it!=ans.rend();it++)
                cout<<(char)(*it+'A');
            cout<<endl;
        }
        
        for(int j=0;j<N;j++)
            graph[j].clear();
    }
}