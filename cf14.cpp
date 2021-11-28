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
        int cnt2 = 0,cnt3 = 0;
        while(n%2 == 0){
            cnt2++;
            n/=2;
        }
        while(n%3 == 0){
            cnt3++;
            n/=3;
        }
        int ans = -1;
        if(n == 1){
            if(cnt2 <= cnt3){
                ans = 2*cnt3-cnt2;
            }
        }
        cout<<ans<<endl;
    }
}