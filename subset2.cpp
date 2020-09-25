#include<bits/stdc++.h>
using namespace std;
void powerset(int arr[],int n)
{
    set<string> subsets;
    int s = exp2(n);
    for(int i=0;i<s;i++)
    {
        string subs = "";
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
                subs += to_string(arr[j]);
        }
        subsets.insert(subs);
    }
    for(string sub:subsets)
        cout<<sub<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    powerset(arr,n);
}