#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long

const int N = 1e9;
string s;
vector<int> evaluate()
{
    pair<int,int> dis;
    stack<pair<int,int>> d;
    stack<int> X;
    int x = 1;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            d.push(dis);
            X.push(x);
            dis = make_pair(0,0);
            x = s[i]-'0';
            i++;
        }
        else if (s[i] == ')')
        {
            pair<int,int> d_prev = d.top();
            d.pop();
            dis.first = (dis.first*x)%N;
            dis.second = (dis.second*x)%N;
            d_prev.first = (d_prev.first+dis.first)%N;
            d_prev.second = (d_prev.second+dis.second)%N;
            dis = d_prev;
            x = X.top();
            X.pop();
        }
        else
        {
            if(s[i] == 'N')
                dis.second--;
            else if(s[i] == 'S')
                dis.second++;
            else if(s[i] == 'E')
                dis.first++;
            else 
                dis.first--;
        }
    }
    dis.first+=1;
    dis.second+=1;
    if(dis.first<=0)
        dis.first+=N;
    if(dis.second<=0)
        dis.second+=N;
    vector<int> ans(2);
    ans[0] = dis.first;
    ans[1] = dis.second;
    return ans;
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        vector<int> ans = evaluate();
        cout<<"Case #"<<i<<": "<<ans[0]<<" "<<ans[1]<<endl;
    }
}