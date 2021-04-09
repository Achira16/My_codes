#include<bits/stdc++.h>
using namespace std;

int sums(int k,vector<vector<int>>& mat)
{
    int n = mat.size(),maxsum = 0;
    vector<vector<int>> ksums(n-k+1,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        int sum = 0;
        for(int j=0;j<k;j++)
        {
            sum+=mat[j][i];
        }
        ksums[0][i] = sum;
        for(int j=1;j<n-k+1;j++)
        {
            ksums[j][i] = ksums[j-1][i] - mat[j-1][i] + mat[j+k-1][i];
        } 
    }
    for(int i=0;i<n-k+1;i++)
    {
        int sum = 0;
        for(int j=0;j<k;j++)
            sum+=ksums[i][j];
        maxsum = max(maxsum,sum);
        for(int j=1;j<n-k+1;j++)
        {
            sum = sum-ksums[i][j-1] + ksums[i][j+k-1];
            maxsum = max(maxsum,sum);
        }
    }
    return maxsum;
}
int func(vector<vector<int>>& mat,int maxSum) 
{
    int n = mat.size(),l = 1,r = n;
    while(l < r-1)
    {
        int mid = (l+r)/2;
        int sum = sums(mid,mat);
        if(sum <= maxSum)
            l = mid;
        else
            r = mid-1;
    }
    if(l == r)
    {
        int sum = sums(l,mat);
        // cout<<sum;
        if(sum <= maxSum)
            return l;
        return 0;
    }
    int sum1 = sums(l,mat),sum2 = sums(r,mat);
    if(sum2 <= maxSum)
        return r;
    else if(sum1 <= maxSum)
        return l;
    return 0;
}
int main()
{
    int n,maxsum;
    cin>>n>>maxsum;
    vector<vector<int>> mat(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    cout<<func(mat,maxsum);
}