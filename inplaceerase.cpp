#include<bits/stdc++.h>
using namespace std;

string erase(string& s)
{
    int j = 0,i = 0;
    while(i < s.size())
    {
        if(i == 0 && s[i] == ' ')
        {
            while(s[i] == ' ') i++;
        }
        else if(s[i] == ' ')
        {
            int k = i;
            i++;
            while(i<s.size() && s[i] == ' ') i++;
            if(i < s.size())
                s[j++] = s[k];
        }
        else
            s[j++] = s[i++];
    }
    for(i=0;i<j;i++)
    {
        char temp = s[i];
        s[i] = s[j-i-1];
        s[j-i-1] = temp;
    }
    return s.substr(0,j);
}
int main()
{
    string s;
    getline(cin,s);
    cout<<erase(s);
}