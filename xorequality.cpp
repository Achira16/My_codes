#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long

ll power(int n)
{
    ll result = 1,a = 2;
    while(n > 0)
    {
        if(n&1)
            result = (result*a)%mod;
        a = (a*a)%mod;
        n/=2;
    }
    return result%mod;
}
int main() {
	// your code goes here
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<power(n-1)<<"\n";
	}
	return 0;
}
