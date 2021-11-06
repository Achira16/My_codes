#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    IOS;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ans = 0,i = 2;
    while(i<n){
        if(arr[i]+k <= 5)
            ans++;
        else
            break;
        i += 3;
    }
    cout<<ans;
}