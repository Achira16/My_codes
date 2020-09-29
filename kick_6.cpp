#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'


int main()
{
    IOS;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        vector<pair<int,int>> mypairs;
        int N,X,d;
        cin>>N>>X;
        for(int j=1;j<=N;j++)
        {
            cin>>d;
            mypairs.push_back(make_pair(ceil((float)d/(float)X),j));
        }
        sort(mypairs.begin(),mypairs.end());
        cout<<"Case #"<<i<<": ";
        for(auto& it:mypairs)
        {
            cout<<it.first<<" ";
        }
        cout<<endl;
    }
}