#include<bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s) {
        int count[26];
        memset(count,0,sizeof(count));
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        stack
        <char> st;
        bool in_st[26];
        memset(in_st,0,sizeof(in_st));
        st.push(s[0]);
        in_st[s[0]-'a'] = 1;
        count[s[0]-'a']--;
        for(int i=1;i<s.size();i++)
        {
            if(!in_st[s[i]-'a'])
            {
            while(!st.empty() && st.top()>s[i] && count[st.top()-'a']>=1)
            {
                in_st[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            in_st[s[i]-'a'] = 1;
            }
            count[s[i]-'a']--;
        }
        string temp = "";
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
        }
        int n= temp.size();
        for(int i=0;i<n/2;i++)
        {
            swap(temp[i],temp[n-i-1]);
        }
        return temp;
    }
int main()
{
    string s;
    cin>>s;
    s = removeDuplicateLetters(s);
    cout<<s;
}