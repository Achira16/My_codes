#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int n = s.size();
        if(s[0] == s[n-1])
            cout<<s<<"\n";
        else{
            s[0] = s[n-1];
            cout<<s<<"\n";
        }
    }
}