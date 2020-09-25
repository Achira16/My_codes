#include<bits/stdc++.h>
using namespace std;
void printsubsets(int arr[],int n,int i,vector<int> ans)
{
    if(i >= n)
    {
        if(ans.size() == 0) cout<<" ";
        else
        {
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    printsubsets(arr,n,i+1,ans);
    ans.push_back(arr[i]);
    printsubsets(arr,n,i+1,ans);
}
void print1(int arr[],int ind,int n,vector<int>& sub,vector<vector<int>>& res)
{
    res.push_back(sub);
    for(int i=ind;i<n;i++)
    {
        sub.push_back(arr[i]);
        print1(arr,i+1,n,sub,res);
        sub.pop_back();
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> ans;
    printsubsets(arr,n,0,ans);
    vector<vector<int>> res;
    vector<int> sub;
    print1(arr,0,n,sub,res);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
}