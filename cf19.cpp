#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n,l,r,k;
        cin>>n>>l>>r>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i] >= l && arr[i] <= r){
                if(arr[i] <= k){
                    ans++;
                    k-=arr[i];
                }
            }
        }
        cout<<ans<<endl;
    }
}