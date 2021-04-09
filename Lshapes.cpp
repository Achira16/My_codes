#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int fun(vector<vector<int>>& mat,int r,int c)
{
    int top[r][c],left[r][c],bottom[r][c],right[r][c];
    for(int i=0;i<c;i++)
        top[0][i] = mat[0][i];
    for(int i=0;i<r;i++)
        left[i][0] = mat[i][0];
    for(int i=0;i<c;i++)
        bottom[r-1][i] = mat[r-1][i];
    for(int i=0;i<r;i++)
        right[i][c-1] = mat[i][c-1];
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j])
                top[i][j] = 1+top[i-1][j];
            else
                top[i][j] = 0;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(mat[i][j])
                left[i][j] = 1+left[i][j-1];
            else
                left[i][j] = 0;
        }
    }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j])
                bottom[i][j] = 1+bottom[i+1][j];
            else
                bottom[i][j] = 0;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=c-2;j>=0;j--)
        {
            if(mat[i][j])
                right[i][j] = 1+right[i][j+1];
            else
                right[i][j] = 0;
        }
    }
    // for(int i=0;i<r;i++)
    // {
    //     for(auto j:top[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<r;i++)
    // {
    //     for(auto j:left[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<r;i++)
    // {
    //     for(auto j:bottom[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<r;i++)
    // {
    //     for(auto j:right[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    int count = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(top[i][j]>=2 && left[i][j]>=2)
            {
                count+=(min(top[i][j]/2,left[i][j])-1 + min(top[i][j],left[i][j]/2)-1);
            }
            if(top[i][j]>=2 && right[i][j]>=2)
            {
                count+=(min(top[i][j]/2,right[i][j])-1 + min(top[i][j],right[i][j]/2)-1);
            }
            if(bottom[i][j]>=2 && left[i][j]>=2)
            {
                count+=(min(bottom[i][j]/2,left[i][j])-1 + min(bottom[i][j],left[i][j]/2)-1);
            }
            if(bottom[i][j]>=2 && right[i][j]>=2)
            {
                count+=(min(bottom[i][j]/2,right[i][j])-1 + min(bottom[i][j],right[i][j]/2)-1);
            }
        }
    }
    return count;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int>> mat(r,vector<int> (c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cin>>mat[i][j];
        }
        cout<<"Case #"<<i<<": "<<fun(mat,r,c)<<"\n";
    }
}