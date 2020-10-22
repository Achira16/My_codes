#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int>& a,vector<int>& b)
{
    return a[0]<b[0];
}
int main()
{
    vector<vector<int>> p = {{1,8},{10,16},{7,12},{2,6}};
    sort(p.begin(),p.end(),comparator);
    for(int i=0;i<4;i++)
    {
        cout<<p[i][0]<<" "<<p[i][1]<<endl;
    }
}