#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& mat,int n)
{
   
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(mat[i][j],mat[i][n-j-1]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    rotate(mat,n);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}