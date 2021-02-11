#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

long solve(vector<int>& arr){
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = arr[i]^prefix[i-1];
    }
    int e = 0,o = 0;
    long ans = 0;
    for(int i=0;i<n;i++){
        if(prefix[i]&1){
            ans+=o;
            o++;
        }
        else{
            ans++;
            ans += e;
            e++;
        }
    }
    return ans;
}
int main()
{
    IOS;
    int t,n;
    cin>>t;
    while(t){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<solve(arr);
        t--;
    }
}