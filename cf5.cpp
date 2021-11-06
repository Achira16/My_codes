#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

long long func(long long start,long long n){
    long long ans;
    if(n%4 == 0) ans = 0;
    else if(n%4 == 1) ans = -n;
    else if(n%4 == 2) ans = 1;
    else ans = n+1;
    if(start == 0) return ans;
    else if(start & 1) return start-ans;
    return start+ans;
}
int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        long long start,n;
        cin>>start>>n;
        cout<<func(start,n)<<"\n";
    }
}