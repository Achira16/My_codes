#include<bits/stdc++.h>
using namespace std;

string solve(int h,int m)
{
    vector<string> times = {" o' clock", "one", "two", "three", "four", 
                        "five", "six", "seven", "eight", "nine", 
                        "ten", "eleven", "twelve", "thirteen", 
                        "fourteen", "quarter", "sixteen", "seventeen", 
                        "eighteen", "nineteen", "twenty", "twenty one", 
                        "twenty two", "twenty three", "twenty four", 
                        "twenty five", "twenty six", "twenty seven", 
                        "twenty eight", "twenty nine","half"};
    string ans = "";
    if(m<=30)
    {
        if(m == 0)
        {
            ans.append(times[h]);
            ans.append(times[m]);
        }
        else
        {
            ans.append(times[m]);
            if(m!=15 && m!=30)
            {
                ans.append(" minutes");
                if(m == 1)
                    ans.pop_back();
            }
            ans.append(" past ");
            ans.append(times[h]);
        }
    }
    else
    {
        m = 60 - m;
        ans.append(times[m]);
        if(m!=15)
        {
            ans.append(" minutes");
            if(m == 1)
                ans.pop_back();
        }
        ans.append(" to ");
        if(h == 12)
            ans.append(times[1]);
        else 
            ans.append(times[h+1]);
    }
    
    return ans;
}
int main()
{
   int h,m;
   cin>>h>>m;
   string ans = solve(h,m);
   cout<<ans;
}