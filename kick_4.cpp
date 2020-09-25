#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int w,h,l,u,r,d;
const int X = 1e5;
const int Y = 1e5;

vector<double> logs(X+Y);

void precomp()
{
    for(int i=2;i<X+Y;i++)
    {
        logs[i] = log2(i) + logs[i-1];
    }
}
double comb(int n,int k)
{
    if(k<0 || k>n)
        return 0;
    return exp2(logs[n]-logs[k]-logs[n-k]-n);
}
double calc()
{
    int i = d+1;
    int j = l-1;
    double prob = 0.0,mult = 1.0;
    int no_of_moves;
    if(d<h)
    {
        while(j>0)
        {
            no_of_moves = i + j - 2;
            if(i>h)
            {
                i = h;
                mult = 0.5;
            }
            prob += mult*comb(no_of_moves,i-1);
            i++;
            j--;
        }
    }
    i = u-1;
    j = r+1;
    mult = 1.0;
    if(r<w)
    {
        while(i>0)
        {
            no_of_moves = i + j - 2;
            if(j>w)
            {
                j = w;
                mult = 0.5;
            }
            prob += mult*comb(no_of_moves,i-1);
            i--;
            j++;
        }
    }
    return prob;
}
int main()
{
    IOS;
    int t;
    precomp();
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>w>>h>>l>>u>>r>>d;
        double ans = calc();
        if(ans == 0)
            cout<<"Case #"<<i<<": 0.0"<<endl;
        else
            cout<<"Case #"<<i<<": "<<ans<<endl;
    }   
}