#include<bits/stdc++.h>
using namespace std;

int minimum(vector<int>& a)
{
    unordered_map
    sort(a.begin(),a.end());
    int min_dist = INT_MAX;
    int max_allowed = 1000000000;
    for(int i=1;i<a.size();i++)
    {
        min_dist = min(min_dist,abs(a[i] - a[i-1])); 
    }
    if(min_dist == INT_MAX)
        return -2;
    if(min_dist > max_allowed)
        return -1;
    return min_dist;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<minimum(a);
}