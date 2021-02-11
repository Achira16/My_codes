#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n';

typedef struct node
{
    int d;
    vector<node*> next;
    node(int x) : d(x) {}
}node;
//0-->covered but not included in
//1-->covered and included
//-1-->neither covered nor included
int ans = 0;
int dfs(node *root)
{
    if(!root) return -1;
    if(root->next.empty()) return -1;
    
    bool incl = false,cov = false;
    for(auto it:root->next)
    {
        int a = dfs(it);
        if(a == -1)
        {
            incl = true;
            cov = true;
        }
        if(a == 1)
        {
            cov = true;
        }
    }
    if(incl)
    {
        ans++;
        return 1;
    }
    if(cov)
        return 0;
    return -1;
}
int main()
{
    IOS;
    int n,ch;
   	cin>>n;
    node *root = new node(n);
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        cin>>ch;
        node *temp = q.front();
        q.pop();
        for(int i=0;i<ch;i++)
        {
            cin>>n;
            node *child = new node(n);
            temp->next.push_back(child);
            q.push(child);
        }
    } 
    int t;
    cin>>t;
    dfs(root);
    if(ans<=t)
    {
        cout<<ans<<" "<<"Mission Successful"<<endl;
    }
    else
    {
        cout<<ans<<" "<<"Mission Unsuccessful"<<endl;
    }
    
}