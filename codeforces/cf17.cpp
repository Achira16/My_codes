#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        if(b-a < -1){
            cout<<-1<<endl;
        }
        else{
            int gr = n-b;
            if(a > b) gr--;
            int low = a-1;
            if(b < a) low--;
            if(gr > n/2-1 || low > n/2-1){
                cout<<-1<<endl;
            }
            else{
                vector<int> ans(n);
                ans[0] = a;
                ans[n/2] = b;
                int ind1 = 1,ind2 = n/2+1;
                if(low > 0){
                    for(int x=1;x<a;x++){
                        if(x != b)
                            ans[ind2++] = x;
                    }
                }
                if(gr > 0){
                    for(int x=b+1;x<=n;x++){
                        if(x!=a)
                            ans[ind1++] = x;
                    }
                }
                if(b-a > 0){
                    for(int x=a+1;x<b;x++){
                        if(ind1 < n/2) ans[ind1++] = x;
                        else if(ind2 < n) ans[ind2++] = x;
                    }
                }
                for(auto i:ans){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
        }
    }
}