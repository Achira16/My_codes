#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,string>

vector<string> func(vector<string>& arr)
{
    map<string,int> mp;
    for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;
    vector<pi> ans;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        ans.push_back({it->second,it->first});
    }
    stable_sort(ans.begin(),ans.end(), [](const pi &a, const pi &b) {
                return a.first > b.first;
            });

    vector<string> res(arr.size());
    for(int i=0;i<ans.size();i++)
    {
        res[i] = ans[i].second+" "+ to_string(ans[i].first);
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<string> ans = func(arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}