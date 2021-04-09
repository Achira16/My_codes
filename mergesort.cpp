#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int l,int mid,int r)
{
    int i=l,j=mid+1,k = 0;
    vector<int> temp(r-l+1);
    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i<=mid)
        temp[k++] = arr[i++];
    while(j<=r)
        temp[k++] = arr[j++];
    k = 0;
    for(int x=l;x<=r;x++)
    {
        arr[x] = temp[k++];
    }
}
void sort(vector<int>& arr,int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main()
{
    vector<int> a = {4,1,3,4,2,9,11,100,99,87};
    sort(a,0,a.size()-1);
    for(int i:a)
    {
        cout<<i<<" ";
    }
}