#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    vector<vector<int>> pairs(n);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        pairs[i].push_back(a);
        pairs[i].push_back(b);
    }
    int ans = n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i^j)
            {
                if(pairs[i][0]>=pairs[j][0] && pairs[i][1]<=pairs[j][1])
                {
                    ans--;
                    break;
                }
            }
        }
    }
    cout<<ans;
}