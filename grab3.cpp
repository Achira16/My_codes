#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& a,int to_remove = -1)
{
    vector<int> diff;
    if(to_remove == -1)
    {
        int i,n = a.size();
        for(i=1;i<n;i++)
        {
            diff.push_back(a[i]-a[i-1]);
        }
        int m = diff.size();
        for(i=0;i<m-1;i++)
        {
            if((diff[i]>0 && diff[i+1]<0) || (diff[i]<0 && diff[i+1]>0))
                continue;
            else
                break;
        }
        if(i == m-1)
            return 1;
    }
    else
    {
        int i,n = a.size();
        for(i=1;i<n;i++)
        {
            if((i == to_remove) || (i-1==to_remove && i-1==0))
                continue;
            if(i-1 == to_remove && i-1 !=0)
                diff.push_back(a[i]-a[i-2]);
            else
                diff.push_back(a[i]-a[i-1]);
        }
        int m = diff.size();
        for(i=0;i<m-1;i++)
        {
            if((diff[i]>0 && diff[i+1]<0) || (diff[i]<0 && diff[i+1]>0))
                continue;
            else
                break;
        }
        if(i == m-1)
            return 1;
    }
    return 0;
}
int solution(vector<int>& a)
{
    int n = a.size(),i;
    for(i=1;i<n;i++)
    {
        if(a[i] >= a[i-1])
            continue;
        else
            break;
    }
    if(i == n)
        return -1;
    for(i=1;i<n;i++)
    {
        if(a[i] <= a[i-1])
            continue;
        else
            break;
    }
    if(i == n)
        return -1;
    if(check(a))
        return 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(check(a,i))
            count++;
    }
    if(!count)
        return -1;
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solution(a);
}