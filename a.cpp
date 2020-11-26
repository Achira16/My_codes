#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& a)
{
    int counts[10];
    memset(counts,0,sizeof(counts));
    for(int x:a)
    {
        counts[x]++;
    }
    for(int i=1;i<10;i++)
    {
        counts[i] += counts[i-1];
    }
    for(int i=9;i>=0;i--)
    {
        counts[i] = counts[i-1];
    }
    counts[0]=0;
    vector<int> b(a.size());
    for(int x:a)
    {
        b[counts[x]++] = x;
    }
    for(int i=0;i<a.size();i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    vector<int> x,y;
    int n = a;
    while(n)
    {
        x.push_back(n%10);
        n/=10;
    }
    n = b;
    while(n)
    {
        y.push_back(n%10);
        n/=10;
    }
    count_sort(y);
    int i = x.size()-1,j = y.size()-1;
    while(i>=0 && j>=0)
    {
        if(x[i]<y[j])
        {
            x[i] = y[j];
            i--;
            j--;
        }
        else 
            i--;
    }
    a = 0;
    for(int k=x.size()-1;k>=0;k--)
    {
        a = a*10+x[k];
    }
    cout<<a;
}