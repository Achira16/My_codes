#include<bits/stdc++.h>
using namespace std;

vector<int> shortestToChar(string s, char c) {
        vector<int> index;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == c)
                index.push_back(i);
        }
        vector<int> ans;
        int j = 0,k,i=0;
        while(i<s.size())
        {
            if(i<=index[0])
            {
                ans.push_back(abs(i-index[0]));
                i++;
            }
            else
            {
                k = j;
                j++;
                if(j<index.size())
                {
                    int n = index[j]-index[k]-1;
                    int x = 0;
                    while(x<n/2)
                    {
                        ans.push_back(abs(i+x-index[k]));
                        x++;
                    }
                    while(x<=n)
                    {
                        ans.push_back(abs(i+x-index[j]));
                        x++;
                    }
                    i += x;
                }
                else
                {
                    while(i<s.size())
                    {
                        ans.push_back(abs(i-index[k]));
                        i++;
                    }
                }
            } 
        }
        return ans;
    }
int main()
{
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    vector<int> ans = shortestToChar(s,ch);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}