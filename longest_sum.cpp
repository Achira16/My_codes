#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    ans.push_back(-1);
    int left = 0,right = 0,sum = 0;
    while (right<n)
    {
        sum+=a[right];
        while (left<right && sum>s)
        {
            sum-=a[left++];
        }
        if(sum == s && (ans.size() == 1 || (ans[1]-ans[0] < right-left)))
        {
            if(ans.size() == 1)
                ans.push_back(right);
            else
                ans[1] = right;
            ans[0] = left;
        }
        right++;
    }
    cout<<ans[0]<<" "<<ans[1];
}