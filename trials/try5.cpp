#include<bits/stdc++.h>
using namespace std;

string operator*(int a,string& s)
{
    string ans = "";
    for(int i=0;i<a;i++)
    {
        ans = ans+s;
    }
    return ans;
}
int main()
{
    string a = "a";
    a = 2*a;
    cout<<a;
}