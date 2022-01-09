#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define pi pair<int,int>

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        vector<pi> temp;
        for(int i=1;i<=n;i++)
            temp.push_back({arr[i],i});
        sort(temp.begin(),temp.end());
        ll sum = 0;
        vector<int> ans(n+1);
        ans[0] = 0;
        ll pos = 1,neg = 1;
        for(int i=n-1;i>=0;i--){
            if(pos <= neg){
                ans[temp[i].second] = pos;
                sum += temp[i].first*2*pos;
                pos++;
            }
            else{
                ans[temp[i].second] = -neg;
                sum += temp[i].first*2*neg;
                neg++;
            }
        }
        cout<<sum<<endl;
        for(int i=0;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}