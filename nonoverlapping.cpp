#include<bits/stdc++.h>
using namespace std;

    struct node
    {
        int s,e,vol;
        node(int a,int b,int c):
        s(a),e(b),vol(c){}
        static bool compare(const node &a,const node &b)
        {
            return a.s < b.s;
        }
    };
    int func(int i,vector<node>& arr,int n,vector<int>& dp)
    {
        if(i >= n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int l = i+1,r = n-1,next_ind = n;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(arr[mid].s >= arr[i].e+1)
            {
                next_ind = mid;
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        int ans = max(arr[i].vol+func(next_ind,arr,n,dp),func(i+1,arr,n,dp));
        dp[i] = ans;
        return ans;
    }
    int phoneCalls(vector<int> start,vector<int> duration,vector<int> volume)
    {
        vector<node> arr;
        int n = start.size();
        for(int i=0;i<n;i++)
            arr.push_back({start[i],start[i]+duration[i],volume[i]});
        sort(arr.begin(), arr.end(),node::compare);
        vector<int> dp(n,-1);
        return func(0,arr,n,dp);
    }


int main()
{
    int n;
    cin>>n;
    vector<int> start(n),dur(n),vol(n);
    for(int i=0;i<n;i++)
        cin>>start[i];
    for(int i=0;i<n;i++)
        cin>>dur[i];
    for(int i=0;i<n;i++)
        cin>>vol[i];
    cout<<phoneCalls(start,dur,vol);
    
}