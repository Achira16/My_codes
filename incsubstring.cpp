#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> solve(string &s)
{
    int length = 1;
    vector<int> ans(s.size());
    ans[0] = length;
    for(int i=1;i<s.size();i++)
    {
        if(s[i] > s[i-1])
            length++;
        else
            length = 1;
        ans[i] = length;
    }
    return ans;
}
int main()
{
    IOS;
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int l;
        string s;
        cin>>l>>s;
        cout<<"Case #"<<t<<": ";
        vector<int> ans = solve(s);
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}