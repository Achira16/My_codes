#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int> count;
    string s;
    cin>>s;
    for(char ch:s)
    {
        count[ch]++;
    }
    for(char ch:s)
    {
        if(count[ch]==1)
        {
            cout<<ch;
            break;
        }
    }
}