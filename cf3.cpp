#include<bits/stdc++.h>
using namespace std;
// #define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int func(int n){
    vector<int> d = {100,20,10,5,1};
    int ans = 0;
    for(auto den:d){
        if(n%den == 0) return ans + n/den;
        ans += n/den;
        n%=den;
    }
    return ans;
}
int main(){
    // IOS;
    int n;
    cin>>n;
    cout<<func(n);
}