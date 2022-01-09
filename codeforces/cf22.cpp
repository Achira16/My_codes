#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll unsigned long long
#define mod 1000000007

ll power(ll a,ll p){
    ll res = 1;
    while(p){
        if(p&1) res = (res*a)%mod;
        p>>=1;
        a = (a*a)%mod;
    }
    return res;
}
int main() {
	// your code goes here
	IOS;
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   vector<int> arr(n);
	   for(int i=0;i<n;i++) cin>>arr[i];
	   int maxel = *max_element(arr.begin(),arr.end());
	   vector<int> freq(maxel+1);
	   int cnt = 0;
	   for(int el:arr){
	       if(freq[el] == 0) cnt++;
	       freq[el]++;
	   }
	   ll ans = power(2,cnt)-1;
	   for(int el=1;el<=maxel;el++){
	       if(freq[el] > 1){
	           ans = (ans%mod + ((freq[el]-1)*power(2,cnt-1))%mod)%mod;
	       }
	   }
	   cout<<ans<<endl;
	}
	return 0;
}
