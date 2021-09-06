#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node
{
    int first,diff,length;
};
int solve(vector<int>& arr)
{
    int n = arr.size();
    unordered_map<int,node> mp;
    int first = arr[0],diff = arr[1]-arr[0],length = 2,ind = 0;
    for(int i=2;i<n;i++)
    {
        if(arr[i]-arr[i-1] != diff)
        {
            mp[ind] = {first,diff,length};
            ind = i-1;
            diff = arr[i]-arr[i-1];
            length = 2;
            first = arr[i-1];
        }
        else
            length++;
    }
    mp[ind] = {first,diff,length};
    // cout<<mp[0].length;
    // for(int i=0;i<n;i++)
    // {
    //     if(mp.find(i)!=mp.end())
    //     {
    //         cout<<i<<" "<<mp[i].first<<" "<<mp[i].diff<<" "<<mp[i].length<<"\n";
    //     }
    // }
    int ans = 2;
    int i = 0,prev = -1;
    while(i<n-1)
    {
        node temp = mp.at(i);
        // cout<<i<<" "<<i+2;
        if(temp.length == 2)
        {
            int a = temp.first,b = arr[i+1],currlen;
            if(mp.find(i+2)!=mp.end())
            {
                node next = mp[i+2];
                currlen = next.length+1;
                if(a == next.first - 2*next.diff)
                    currlen++;
                ans = max(ans,currlen);
            }
            if(prev!=-1)
            {
                node prev_temp = mp[prev];
                currlen = prev_temp.length+1;
                if(i+2 < n && arr[i+2] == prev_temp.first + currlen*prev_temp.diff)
                {
                    currlen++;
                    if(mp.find(i+2)!=mp.end())
                    {
                        node next = mp[i+2];
                        if(next.diff == prev_temp.diff)
                            currlen = prev_temp.length+next.length+1;
                    }
                }
                ans = max(ans,currlen);
            }
            node next = mp[i+1];
            currlen = next.length+1;
            if(i-1>=0 && arr[i-1] == next.first-2*next.diff)
                currlen++;
            ans = max(ans,currlen);
        }
        else
            ans = max(ans,temp.length);
        prev = i;
        i += (temp.length-1);
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Case #"<<t<<": "<<solve(arr)<<"\n";
    }
}