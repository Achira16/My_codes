#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& A)
{
    unordered_map<int,int> mp;
    for(auto a:A)
    {
        mp[a]++;
    }
    int count = 0,max_allowed = 1000000000;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second > 1)
        {
            count += ((i->second * (i->second-1))/2);
        }
        if(count > max_allowed)
            return max_allowed;
    }
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