#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void update(vector<int>& st,int si,int sl,int sr,int ind,int num)
{
    if(ind < sl || ind > sr)
        return;
    st[si] = min(st[si],num);
    if(sl != sr)
    {
        int mid = (sl+sr)/2;
        update(st,2*si+1,sl,mid,ind,num);
        update(st,2*si+2,mid+1,sr,ind,num);
    }
}
int range_min(vector<int>& st,int si,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r)
        return st[si];
    if(sr<l || sl>r)
        return INT_MAX;
    int mid = (sl+sr)/2;
    return min(range_min(st,2*si+1,sl,mid,l,r),range_min(st,2*si+2,mid+1,sr,l,r));
}
int construct_st_util(vector<int>& st,int si,int l,int r,vector<int>& arr)
{
    if(l == r)
    {
        st[si] = arr[l];
        return st[si];
    }
    int mid = (l+r)/2;
    st[si] = min(construct_st_util(st,2*si+1,l,mid,arr),construct_st_util(st,2*si+2,mid+1,r,arr));
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
            arr[b] = c;
            update(seg_tree,0,0,n-1,b,c);
        }
        else //Sum
        {
            cout<<"Query "<<i<<": "<<range_min(seg_tree,0,0,n-1,b,c)<<"\n";
        }
    }
}