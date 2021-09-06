#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

vector<int> solve(vector<int>& A)
{
    int n = A.size();
    vector<int> up(n,INT32_MAX),down(n,INT32_MAX);
    if(A[0] == 1)
        up[0] = 0;
    if(A[n-1] == 2)
        down[n-1] = 0;
    for(int i=1;i<n;i++)
    {
        if(A[i] == 1)
            up[i] = 0;
        else if(A[i] == 0)
        {
            if(up[i-1] != INT32_MAX)
                up[i] = up[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(A[i] == 2)
            down[i] = 0;
        else if(A[i] == 0)
        {
            if(down[i+1] != INT32_MAX)
                down[i] = down[i+1]+1;
        }
    }
    vector<int> results(n);
    for(int i=0;i<n;i++)
        results[i] = min(up[i],down[i]);
    results[0] = 0;
    return results;
}
int main() {
	// your code goes here
	IOS;
	int t;
    cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int> A(n),B(m);
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    for(int i=0;i<m;i++)
	        cin>>B[i];
	    vector<int> dists = solve(A);
	    for(int i=0;i<B.size();i++)
	    {
            if(dists[B[i]-1]!=INT32_MAX)
	            cout<<dists[B[i]-1]<<" ";
            else
                cout<<-1<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
