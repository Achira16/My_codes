#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n';

typedef struct node
{
    int d;
    int vc;
    vector<node*> next;
    node(int x) : d(x) {}
}node;
int vertexCoverTree(node *root)
{
    if(!root)
        return 0;
    if(root->next.size()==0)    
        return 0;
    if(root->vc)
        return root->vc;
    int size_incl = 1;
    for(auto it=root->next.begin();it!=root->next.end();it++)
    {
        size_incl += vertexCoverTree(*it);
    }
    int size_excl = 0;
    for(auto it=root->next.begin();it!=root->next.end();it++)
    {
        size_excl += 1;
        for(auto j = (*it)->next.begin();j!=(*it)->next.end();j++)
        {
            size_excl += vertexCoverTree(*j);
        }
    }
    root->vc = min(size_incl,size_excl);
    return root->vc;
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
            if(n)
            {
                node *child = new node(n);
                temp->next.push_back(child);
                q.push(child);
            }
            
        }
    } 
    int t;
    cin>>t;
    int ans = vertexCoverTree(root);
    if(ans<=t)
        cout<<ans<<" Mission Successful";
    else
    {
        cout<<ans<<" Mission Unsuccessful";
    }
    
    return 0;
}