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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans = 0;
        sort(arr.begin(),arr.end(),[](int &a,int &b){
            return a%2 < b%2;
        });
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans += __gcd(arr[i],2*arr[j]) > 1;
            }
        }
        cout<<ans<<endl;
    }
}