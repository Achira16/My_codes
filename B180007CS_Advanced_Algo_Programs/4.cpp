//modified naive string matching
#include<bits/stdc++.h>
using namespace std;

//all characters in the string are different
void match(string& pat,string& s)
{
    int i = 0;
    int n = s.size(),m = pat.size();
    while(i <= (n-m))
    {
        int j = 0;
        while(j < m)
        {
            if(s[i+j]!=pat[j])
                break;
            j++;
        }
        if(j >= pat.size())
        {
            cout<<"Pattern found at shift "<<i<<endl;
        }
        if(j>0)
            i+=j;
        else
            i++;
    }
}
int main()
{
    string pat,s;
    cin>>pat>>s;
    match(pat,s);
}