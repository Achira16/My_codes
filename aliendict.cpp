#include<bits/stdc++.h>
using namespace std;

void topologicalsort(int i,vector<vector<int>>& graph,vector<bool>& vis,stack<int>& st)
{
    vis[i] = 1;
    for(auto j:graph[i])
    {
        if(!vis[j])
            topologicalsort(j,graph,vis,st);
    }
    st.push(i);
}
vector<char> getAlienLanguage(string* dict, int n)
{
    //Write your code here 
    unordered_set<int> chars;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<dict[i].size();j++)
        {
            if(chars.find(dict[i][j]-'a') == chars.end())
                chars.insert(dict[i][j]-'a');
        }
    }
    int l = chars.size();
    vector<vector<int>> graph(l);
    for(int i=0;i<n-1;i++)
    {
        string s1 = dict[i],s2 = dict[i+1];
        for(int j=0;j<min(s1.size(),s2.size());j++)
        {
            if(s1[j] != s2[j])
            {
                graph[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<bool> vis(l,0);
    stack<int> st;
    for(int i=0;i<l;i++)
    {
        if(!vis[i])
            topologicalsort(i,graph,vis,st);
    }
    vector<char> ans(l);
    int k = 0;
    while(!st.empty())
    {
        ans[k++] = st.top()+'a';
        st.pop();
    }
    return ans;
}
