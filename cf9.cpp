#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void func(string& s,int n){
    int count = 0;
    for(int i=0;i<n;i++){
        count += (s[i] != '?');
    }
    if(!count)
        s[0] = 'R';
    for(int i=1;i<n;i++){
        if(s[i] == '?' && s[i-1] != '?')
            s[i] = s[i-1]^'R'^'B';
    }
    for(int i=n-1;i>=0;i--){
        if(s[i] == '?' && s[i+1] != '?')
            s[i] = s[i+1]^'R'^'B';
    }
}
int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        func(s,n);
        cout<<s<<"\n";
    }
}