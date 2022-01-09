#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int msb;
        for(int i=30;i>=0;i--){
            if(r & (1<<i)){
                msb = i;
                break;
            }
        }
        int ans = INT_MAX,tot = r-l+1;
        for(int i=0;i<=msb;i++){
            int cnt = 0,mask = 1<<i;
            for(int j=l;j<=r;j++){
                if(j & mask) cnt++;
            }
            ans = min(ans,tot-cnt);
        }
        cout<<ans<<endl;
    }
}
