#include<bits/stdc++.h>
using namespace std;

void compute(vector<int>& ans,int n,int k)
{
    if(n<1)
    {
        for(int a:ans)
        {
            cout<<a<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<k;i++)
    {
        ans[n-1] = i;
        compute(ans,n-1,k);
    }
}
int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> ans(n);
    compute(ans,n,k);
}