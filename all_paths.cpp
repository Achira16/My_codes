#include<bits/stdc++.h>
using namespace std;
void findpath(int *mat,int i,int j,int m,int n,int *path,int c)
{
    if(i == m-1)
    {
        for(int k=j;k<n;k++)
        {
            path[c] = *(mat+i*n+k);
            c++;
        }
        for(int l=0;l<c;l++)
        {
            cout<<path[l]<<" ";
        }
        cout<<endl;
        return;
    }
    if(j == n-1)
    {
        for(int k=i;k<m;k++)
        {
            path[c] = *(mat+k*n+j);
            c++;
        }
        for(int l=0;l<c;l++)
        {
            cout<<path[l]<<" ";
        }
        cout<<endl;
        return;
    }
    path[c] = *(mat+i*n+j);
    findpath(mat,i+1,j,m,n,path,c+1);
    findpath(mat,i,j+1,m,n,path,c+1);
}
void print_all(int *mat,int m,int n)
{
    int *path = new int[m+n];
    findpath(mat,0,0,m,n,path,0);
}
int main()
{
    int m,n;
    cin>>m>>n;
    int mat[m][n] = {{1,2,3},{4,5,6},{7,8,9}};
    print_all(*mat,m,n);
}