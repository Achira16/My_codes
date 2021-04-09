#include<bits/stdc++.h>
using namespace std;

void swap(int& a,int& b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
void transpose(vector<vector<int>>& mat)
{
    int n = mat.size();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
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
    transpose(mat);
    for(int i=0;i<n;i++)
    {
        for(int j:mat[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}