#include<bits/stdc++.h>
using namespace std;
void rev(string& s,int i,int n)
{
    if(i > n/2)
        return;
    char c = s[i];
    s[i] = s[n-i-1];
    s[n-i-1] = c;
    rev(s,i+1,n);
}
int main()
{
    string s;
    getline(cin,s);
    rev(s,0,s.size());
    cout<<s;
}