#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int func(string& num){
    int n = num.size();
    vector<int> prefix(n);
    for(int i=1;i<n;i++){
        if(num[i] == '0')
            prefix[i] = prefix[i-1] + 1;
    }
    vector<string> arr = {"00", "25", "50", "75"};
    int ans = INT_MAX;
    for(auto s:arr){
        bool found = 0;
        for(int i=n-1;i>=0;i--){
            if(num[i] == s[1]){
                for(int j=i-1;j>=0;j--){
                    if(num[j] == s[0]){
                        ans = min(ans,n-j-2);
                        found = 1;
                        break;
                    }
                }
            }
            if(found) break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(num[i] == '0'){
            ans = min(ans,n-1-prefix[i-1]);
        }
    }
    return ans;
}
int main(){
    IOS;
    int T;
    cin>>T;
    while(T--){
        long long n;
        cin>>n;
        string num = to_string(n);
        cout<<func(num)<<"\n";
    }
}