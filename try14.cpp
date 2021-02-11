#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path)
{
    stack<string> s;
    int i=0;
    while(i<path.size())
    {
        if(path[i] == '/')
        {
            while(path[i]=='/')
            {
                i++;
            }
        }
        else 
        {
            int count = 0,j=i;
            bool flag = false;
            if(path[i] == '.')
            {
                i++;
                count++;
                flag = true;
            }
            while(i<path.size() && path[i]!='/')
            {
                if(flag && path[i]=='.')
                    count++;
                else if(flag && path[i]!='.')
                    flag = false;
                i++;
            }
            if(flag && count == 2 && !s.empty())
                s.pop();
            else if(flag && count >= 3 || !flag)
                s.push(path.substr(j,i-j));
        }
    }
    string res;
    if(s.empty())
        return "/";
    while(!s.empty())
    {
        res = '/'+s.top()+res;
        s.pop();
    }
    return res;
}
int main()
{
    string path;
    cin>>path;
    cout<<simplifyPath(path);
}