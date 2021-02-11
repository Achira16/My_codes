#include<bits/stdc++.h>
using namespace std;

struct node
{
    string key;
    node *left,*right;
    node(string s):key(s),left(NULL),right(NULL){}
};
node* construct(node *root,vector<vector<int>>& r,int i,int j)
{
    if(j == i-1)
    {
        string key = "d"+to_string(i-1);
        return new node(key);
    }
    root = new node("k"+to_string(r[i][j]));
    root->left = construct(root->left,r,i,r[i][j]-1);
    root->right = construct(root->right,r,r[i][j]+1,j);
    return root;
}
void solve(vector<float>& p,vector<float>& q)
{
    int n = p.size()-1;
    vector<vector<float>> dp(n+2,vector<float> (n+1,0)),w(n+2,vector<float> (n+1,0));
    vector<vector<int>> root(n+1,vector<int> (n+1));    
    for(int i=1;i<=n+1;i++)
    {
        w[i][i-1] = q[i-1];
        dp[i][i-1] = w[i][i-1];
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            
            int j = i+l-1;
            w[i][j] = w[i][j-1]+p[j]+q[j];
            float q = INT32_MAX;
            for(int k=i;k<=j;k++)
            {
                float t = dp[i][k-1]+dp[k+1][j]+w[i][j];
                if(t<q)
                {
                    q = t;
                    root[i][j] = k;
                }
            }
            dp[i][j] = q;
        }
    }
    cout<<dp[1][n]<<"\n";
    node *rt = NULL;
    rt = construct(rt,root,1,n);
    queue<node*> qu;
    qu.push(rt);
    cout<<rt->key<<" ";
    while(!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();
        if(temp->left)
        {
            cout<<temp->left->key<<" ";
            qu.push(temp->left);
        }
        else
            cout<<"null ";
        if(temp->right)
        {
            cout<<temp->right->key<<" ";
            qu.push(temp->right);
        }
        else
            cout<<"null ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<float> p(n+1),q(n+1);
    p[0] = 0;
    for(int i=1;i<n+1;i++)
        cin>>p[i];
    for(int i=0;i<n+1;i++)
        cin>>q[i];
    solve(p,q);
}