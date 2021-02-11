//naive string matching
#include<bits/stdc++.h>
using namespace std;

void match(string& pat,string& s)
{
    int n = s.size(),m = pat.size();
    for(int i=0;i<=(n-m);i++)
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(s[i+j] != pat[j])
                break;
        }
        if(j >= pat.size())
        {
            cout<<"Pattern found at shift "<<i<<endl;
        }
    }
}
int main()
{
    string pat,s;
    cin>>pat>>s;
    match(pat,s);
}