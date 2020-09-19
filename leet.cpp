#include<bits/stdc++.h>
using namespace std;

vector<string> split(string& s,char delim = ' ')
{
    vector<string> spl;
    for(int i=0;i<s.size();i++)
    {
        int j = i;
        while(s[i]!=delim && i<s.size())
            i++;
        spl.push_back(s.substr(j,i-j));
    }
    return spl;
}
bool sol(string& s,string& pat)
{
    map<string,string> m1;
    map<char,string> m2;
    vector<string> words = split(s);
    bool flag = true;
    if(pat.length()!=words.size())
        return 0;
    for(int i=0;i<pat.length();i++)
    {
        if(m1[words[i]] == "")
        {
            m1[words[i]].push_back(pat[i]);
        }
        else if(m1[words[i]] != pat.substr(i,1))
        {
            flag = false;
            return flag;
        }
        if(m2[pat[i]] == "")
        {
            m2[pat[i]] = words[i];
        }
        else if(m2[pat[i]] != words[i])
        {
            flag = false;
            return flag;
        }
        
    }
    return flag;
}
int main()
{
    string pat;
    getline(cin,pat);
    string s;
    getline(cin,s);
    bool flag = sol(s,pat);
    cout<<flag;
}