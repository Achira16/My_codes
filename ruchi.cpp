#include<bits/stdc++.h>
using namespace std;

int range_max(vector<int>& st,int si,int sl,int sr,int l,int r)
{
    if(sl>=l && sr<=r)
        return st[si];
    if(sr<l || sl>r)
        return INT_MIN;
    int mid = (sl+sr)/2;
    return max(range_max(st,2*si+1,sl,mid,l,r),range_max(st,2*si+2,mid+1,sr,l,r));
}
int construct_st_util(vector<int>& st,int si,int l,int r,vector<int>& arr)
{
    if(l == r)
    {
        st[si] = arr[l];
        return st[si];
    }
    int mid = (l+r)/2;
    st[si] = max(construct_st_util(st,2*si+1,l,mid,arr),construct_st_util(st,2*si+2,mid+1,r,arr));
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
void func(vector<int>& arr,vector<int>& q)
{
    vector<int> segtree = construct_st(arr,arr.size());
    for(int i=0;i<q.size();i++)
    {
        int ind = q[i]-1;
        int r_ans = 1,l = ind+1,r = arr.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(range_max(segtree,0,0,arr.size()-1,ind,mid) == arr[ind])
            {
                r_ans = max(r_ans,mid-ind+1);
                l = mid+1;
            }
            else
                r = mid-1;
        }
        int l_ans = 1;
        l = 0,r = ind-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(range_max(segtree,0,0,arr.size()-1,mid,ind) == arr[ind])
            {
                l_ans = max(l_ans,ind-mid+1);
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<<r_ans+l_ans-1<<"\n";
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),queries(k);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<k;i++)
        cin>>queries[i];
    func(arr,queries);
}