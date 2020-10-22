#include<bits/stdc++.h>
using namespace std;
bool check(string& s,string& t)
{
    int i = s.length()-1,j = t.length()-1;
    int count = 0;
    while(i>=0 && j>=0)
    {
        while((s[i] == '#' || count>0) && i>=0)
        {
            (s[i]=='#')?(count++):(count--);
            i--;
        }
        while((t[j] == '#' || count>0) && j>=0)
        {
            (t[j]=='#')?(count++):(count--);
            j--;
        }
        if(i>=0 && j>=0)
        {
           if(s[i]!=t[j])
             return false;
        }
        i--;
        j--;
    }
    if(j == i)
        return true;
    return false;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<check(s,t);
    vector<int> v;
}