#include<bits/stdc++.h>
using namespace std;

void swap(int &x,int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int partition(vector<int>& arr,int l,int r)
{
    int pi = arr[r],i = l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pi)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void sort(vector<int>& arr,int l,int r)
{
    if(l<r)
    {
        int pi = partition(arr,l,r);
        sort(arr,l,pi-1);
        sort(arr,pi+1,r);
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