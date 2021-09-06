#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void findEmptyslot(vector<int>& st,int si,int sl,int sr,int num,vector<int>& arr,int height)
{
    st[si]--;
    if(sl == sr)
    {
        arr[sl] = height;
        return;
    }
    int mid = (sl+sr)/2;
    if(st[2*si+1] >= num)
        return findEmptyslot(st,2*si+1,sl,mid,num,arr,height);
    return findEmptyslot(st,2*si+2,mid+1,sr,num-st[2*si+1],arr,height);
}
int construct_st_util(vector<int>& st,int si,int l,int r,vector<int>& arr)
{
    if(l == r)
    {
        st[si] = 1;
        return st[si];
    }
    int mid = (l+r)/2;
    st[si] = construct_st_util(st,2*si+1,l,mid,arr) + construct_st_util(st,2*si+2,mid+1,r,arr);
    return st[si];
}
vector<int> construct_st(vector<int>& arr,int n)
{
    int h = ceil(log2(n));
    int size = 2*(int)pow(2,h)-1;
    vector<int> stree(size,0);
    construct_st_util(stree,0,0,n-1,arr);
    return stree;
}
vector<int> findOrder(vector<int> &height, vector<int> &infront) {
	// Write your code here
    int n = height.size();
    vector<int> result(n,-1);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[height[i]] = infront[i];
    }
    sort(height.begin(),height.end());
    vector<int> seg_tree = construct_st(result,n);
    for(int i=0;i<n;i++)
    {
        findEmptyslot(seg_tree,0,0,n-1,mp[height[i]]+1,result,height[i]);
    }
    return result;
}
int main()
{
    IOS;
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int> heights(n);
        for(int i=0;i<n;i++)    
            cin>>heights[i];
        vector<int> infront(n);
        for(int i=0;i<n;i++)    
            cin>>infront[i];
        vector<int> res = findOrder(heights, infront);
        for(auto i:res)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}