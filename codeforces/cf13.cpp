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
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        bool bad = 0;
        for(int i=0;i<n;i++){
            if(a[i] == b[i] || a[i]+1 == b[i]) continue;
            else{
                bad = 1;
                break;
            }
        }
        if(bad){
            cout<<"NO"<<endl;
        }  
        else{
            cout<<"YES"<<endl;
        }
    }
}