#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

// void recur(int i,string& s,vector<string>& ans,int n,char* input1,vector<string>& mp)
// {
//     if(i >= n)
//     {
//         ans.push_back(s);
//         return;
//     }
//     for(auto c:mp[input1[i]-'0'])
//     {
//         s.push_back(c);
//         recur(i+1,s,ans,n,input1,mp);
//         s.pop_back();
//     }
// }
// string func(char* input1,int input2,int input3)
// {
//     string s;
//     vector<string> ans;
//     vector<string> mp(10);
//     mp[2] = "ABC";
//     mp[3] = "DEF";
//     mp[4] = "GHI";
//     mp[5] = "JKL";
//     mp[6] = "MNO";
//     mp[7] = "PQRS";
//     mp[8] = "TUV";
//     mp[9] = "WXYZ";
//     recur(0,s,ans,input2,input1,mp);
//     return ans[input3-1];
// }
// int main()
// {
//     // int n,d;
//     // char s[n+1];
//     // cin>>n>>d>>s;
//     // // cout<<s;
//     // cout<<func(s,n,d);
//     // // cout<<func(n,arr,s);
//     // printf("helo");
//     fork();
//     printf("helo");
// }
class String
{
    void operator=(const char*){}
    public:
    explicit String(char ch,int n=1){}
    String(const char *p){}
};
int main()
{
    String x = "aaa";
}