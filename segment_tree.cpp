#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void update(vector<int>& st,int si,int sl,int sr,int ind,int diff)
{
    if(ind < sl || ind > sr)
        return;
    st[si] += diff;
    if(sl != sr)
    {
        int mid = (sl+sr)/2;
        update(st,2*si+1,sl,mid,ind,diff);
        update(st,2*si+2,mid+1,sr,ind,diff);
    }
}

int findsum(vector<int>& st,int ind,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r)
        return st[ind];
    if(sr<l || sl>r)
        return 0;
    int mid = (sl+sr)/2;
    return findsum(st,2*ind+1,sl,mid,l,r)+findsum(st,2*ind+2,mid+1,sr,l,r);
}

int construct(vector<int>& st,int ind,int l,int r,vector<int>& nums)
{
    if(l == r)
    {
        st[ind] = nums[l];
        return st[ind];
    }
    int mid = (l+r)/2;
    st[ind] = construct(st,2*ind+1,l,mid,nums)+construct(st,2*ind+2,mid+1,r,nums);
    return st[ind];
}
vector<int> construct_st(vector<int>& arr,int n)
{
    int h = ceil(log2(n));
    int size = 2*(int)pow(2,h)-1;
    vector<int> stree(size,0);
    construct(stree,0,0,n-1,arr);
    return stree;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> seg_tree = construct_st(arr,n);
    // for(auto i:seg_tree)
    // {
    //     cout<<i<<" ";
    // }
    int Q,a,b,c;
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>a>>b>>c;
        if(a == 1)//Update 
        {
            int diff = c - arr[b];
            update(seg_tree,0,0,n-1,b,diff);
        }
        else //Sum
        {
            cout<<"Query "<<i<<": "<<findsum(seg_tree,0,0,n-1,b,c)<<"\n";
        }
    }
}