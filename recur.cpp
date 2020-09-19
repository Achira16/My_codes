#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    map<char,int> count;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        count[s[i]]++;
        if(count[s[i]]>1)
        {
            cout<<s[i];
            break;
        }
    }
}