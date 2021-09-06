#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007

ll power(ll a,ll b)
{
    ll result = 1;
    while(b)
    {
        if(b&1)
           result = ((result%mod)*(a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return result;
}
int main() {
	// your code goes here
	IOS;
	int T;
	cin>>T;
	while(T--)
	{
	    int n,m;
	    cin>>n>>m;
	    ll res = power(2,n)-1;
	    ll ans = power(res,m);
	    cout<<ans<<"\n";
	}
	return 0;
}
