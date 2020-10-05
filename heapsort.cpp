#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a)
{
    int max,n = a.size()-1;
    for(int i=n/2-1;i>=0;i--)
    {
        max = i;
        do
        {
            i = max;
            int l = 2*i+1,r = 2*i+2;
            if(l<=n && a[l]>a[max])
                max = l;
            if(r<=n && a[r]>a[max])
                max = r;
            swap(a[i],a[max]);
        }while(max!=i);
    }
}
void heapsort(vector<int>& a)
{
    heapify(a);
    int n = a.size()-1;
    while(n>0)
    {
        swap(a[0],a[n]);
        n--;
        int max = 0,i;
        do
        {
            i = max;
            int l = 2*i+1,r = 2*i+2;
            if(l<=n && a[l]>a[max])
                max = l;
            if(r<=n && a[r]>a[max])
                max = r;
            swap(a[i],a[max]);
        }while(max!=i);  
    }
}
int main()
{
    vector<int> a;
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        a.push_back(d);
    }
    heapsort(a);
    for(auto& it:a)
    {
        cout<<it<<" ";
    }
}