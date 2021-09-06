#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int minSwap (int N, int M, int K, string &S, vector<char> &arr)
{
    // Write your code here.
    unordered_map<char,int> mp;
    bool flag = 0;
    for(auto c:arr)
    {
        mp[c]++;
    }
    vector<vector<int>> freq(K,vector<int> (26,0));
    for(int i=0;i<N;i++)
    {
        freq[i%K][S[i]-'a']++;
    }
    int total_pos = N/K,res = 0;
    for(int i=0;i<K;i++)
    {
        int max_freq = 0;
        for(int j=0;j<26;j++)
        {
            if(freq[i][j] > max_freq && mp[j+'a'])
            {
                max_freq = freq[i][j];
            }
        }
        res += total_pos-max_freq + ((i < N%K)?1:0);
    }
    return res;
}
int main()
{
    IOS;
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,K;
        cin>>N>>M>>K;
        string s;
        cin>>s;
        vector<char> arr(M);
        for(int i=0;i<M;i++)
            cin>>arr[i];
        cout<<minSwap(N,M,K,s,arr)<<endl;
    }
}