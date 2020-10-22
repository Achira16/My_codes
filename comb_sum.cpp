#include<bits/stdc++.h>
using namespace std;

vector<int> a;
set<vector<int>> m;
void findsum(vector<int>& ans,int sum,int i)
{
    if(sum == 0 && !ans.empty())
    {
        m.insert(ans);
        return;
    }
    if(sum < 0 || i>= a.size())
        return;
    int mul = 1,c = 0;
    while(a[i]*mul <= sum)
    {
        ans.push_back(a[i]);
        c++;
        findsum(ans,sum-(a[i]*mul),i+1);
        mul++;
    }
    if(!ans.empty())
    {
        int temp = a[i];
        while (c)
        {
            ans.pop_back();
            c--;
        }
    }
    findsum(ans,sum,i+1);
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int sum;
    cin>>sum;
    vector<int> ans;
    findsum(ans,sum,0);
    vector<vector<int>> res(m.begin(),m.end());
    for(auto& it:res)
    {
        for(auto& jt:it)
            cout<<jt<<" ";
        cout<<endl;
    }
}