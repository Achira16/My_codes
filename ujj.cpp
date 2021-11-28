#include<bits/stdc++.h>
using namespace std;

string operator*(int a,string& s){
    string ans = "";
    for(int i=0;i<a;i++)
    {
        ans = ans+s;
    }
    return ans;
}
int romanToInt(string s) {
    unordered_map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    char prev = 'N';
    int n = s.size();
    int sum = mp[s[n-1]];
    for(int i=n-2;i>=0;i--)
    {
        if(s[i] == 'I')
        {
            if(s[i+1] == 'V'||s[i+1] == 'X')
                sum-=mp[s[i]];
            else
                sum+=mp[s[i]];
        }
        else if(s[i] == 'X')
        {
            if(s[i+1] == 'L'||s[i+1]=='C')
                sum-=mp[s[i]];
            else
                sum+=mp[s[i]];
        }
        else if(s[i] == 'C')
        {
            if(s[i+1] == 'D'||s[i+1]=='M')
                sum-=mp[s[i]];
            else
                sum+=mp[s[i]];
        }
        else
        {
            sum+=mp[s[i]];
        }
    }
    return sum;
}
string intToRoman(int num) {
    unordered_map<int,string> mp;
    mp[1] = "I",mp[5] = "V",mp[10] = "X",mp[50] = "L",mp[100] = "C",mp[500] = "D",mp[1000] = "M";
    string ans = "";
    int power = 1;
    while(num)
    {
        int d = num%10;
        if(d<5)
        {
            if(d == 4)
                ans = mp[1*power]+mp[5*power]+ans;
            else
                ans = d*mp[1*power]+ans;
        }
        else
        {
            if(d == 5)
                ans = mp[5*power] + ans;
            else if(d-5 == 4)
                ans = mp[1*power] + mp[10*power] + ans;
            else
                ans = mp[5*power] + (d-5)*mp[1*power] + ans;
        }
        num/=10;
        power*=10;
    }
    return ans;
}

string StringChallenge(string& str){
    int num = romanToInt(str);
    return intToRoman(num);
}
int main(){
    string s;
    cin>>s;
    cout<<StringChallenge(s);
}