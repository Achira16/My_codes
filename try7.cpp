#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

void solve(int n)
{
    char ch;
    long int x;
    long int l = INT64_MIN;
    long int u = INT64_MAX;
    while(n){
        cin>>ch>>x;
        if(ch == 'R'){
            l = max(l,x);
        }
        else if(ch == 'L'){
            u = min(u,x);
        }
        n--;
    }
    if(u-l <= 1)
        cout<<-1;
    else if(u == INT64_MAX || l == INT64_MIN)
        cout<<-1;
    else{
        cout<<u-l-1;
    }
    cout<<endl;
}
int main(){
    IOS;
    int t,n;
    cin>>t;
    while(t){
        cin>>n;
        solve(n);
        t--;
    }
}