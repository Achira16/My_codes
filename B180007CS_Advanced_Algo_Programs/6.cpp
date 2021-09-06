//Knuth-Morris-Pratt algorithm
#include<bits/stdc++.h>
using namespace std;

void KMPmatch(string& pat,string& s)
{
    int n = s.size(),m = pat.size();
    vector<int> pi(m);
    //compute pi table
    pi[0] = 0;
    int k = 0;
    for(int i=1;i<m;i++)
    {
        while(k>0 && pat[k]!=pat[i])
        {
            k = pi[k-1];
        }
        if(pat[k] == pat[i]) k++;
        pi[i] = k;
    }
    for(auto i:pi)
    {
        cout<<i<<" ";
    }
    //main algorithm
    k = 0;
    for(int i=0;i<=n;i++)
    {
        while(k>0 && pat[k]!=s[i])
        {
            k = pi[k-1];
        }
        if(pat[k] == s[i]) k++;
        if(k == m)
        {
            cout<<"Pattern occurs at shift "<<i-m+1<<endl;
            k = pi[k-1];
        }
    }
}
int main()
{
    string pat,text;
    cout<<"Enter the pattern: ";
    getline(cin,pat);
    cout<<"Enter the text: ";
    getline(cin,text);
    KMPmatch(pat,text);
}