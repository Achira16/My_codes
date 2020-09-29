#include<bits/stdc++.h>
using namespace std;
int calc(vector<int>& times,int dur)
{
    int total = dur;

    for(int i=1;i<times.size();i++)
    {
        if(times[i]-times[i-1] >= dur)
        {
            total += dur;
        }
        else
        {
            int diff = dur - (times[i]-times[i-1]);
            total += (dur-diff);
        }
    }
    return total;
}
int main()
{
    int dur,n;
    cin>>dur>>n;
    vector<int> times(n);
    for(int i=0;i<n;i++)
         cin>>times[i];
    int ans = calc(times,dur);
    cout<<ans;
}