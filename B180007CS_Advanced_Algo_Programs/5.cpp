//Rabin-Karp algorithm
#include<bits/stdc++.h>
using namespace std;

int power(int a,int p)
{
    if(p == 0) return 1;
    if(p == 1) return a;
    int res = power(a,p/2);
    if(p & 1)
        return res*res*a;
    return res*res;
}
void match(string& pat,string& s)
{
    //considering d as 10(decimal) and q as 100007 which is a prime number
    int d = 10,q = 100007,m = pat.size(),n = s.size();
    int p = 0,t = 0,h = power(d,m-1)%q;
    for(int i = 0; i < m;i++)
    {
        p = (d*p+(pat[i]-'0'))%q;
        t = (d*t+(s[i]-'0'))%q;
    }
    for(int i=0;i<=(n-m);i++)
    {
        if(p == t)
        {
            int j = 0;
            while(j<m)
            {
                if(s[i+j]!=pat[j])
                    break;
                j++;
            }
            if(j>=m)
            {
                cout<<"Pattern occurs at shift "<<i<<endl;
            }
        }
        if(i<(n-m)){
        int x = d*(t - (s[i]-'0')*h)+(s[i+m]-'0');
        if(x < 0)
        {
            t = x - q*floor(float(x)/float(q));
        }
        else
        {
            t = x%q;
        }
        }
    }
}
int main()
{
    string pat,s;
    cin>>pat>>s;
    match(pat,s);
}