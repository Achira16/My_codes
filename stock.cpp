#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<int>& arr)
{
    if(arr.size() <= 1)
        return {{}};
    vector<vector<int>> ans;
    int j = -1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i] > arr[i-1])
        {
            if(j == -1)
            {
                ans.push_back({i-1,i});
                j = ans.size()-1;
            }
            else
                ans[j][1] = i;
        }
        else
            j = -1;
    }
    return ans;
}
int main()
{
    vector<int> arr;
    string s;
    cin>>s;
    if(s[0] == '{')
    {
        s.erase(0,1);
        s.erase(s.size()-1);
    }
    stringstream ss(s);
    while(ss.good())
    {
        string sub;
        getline(ss, sub, ',');
        arr.push_back(stoi(sub));
    }
    vector<vector<int>> ans = func(arr);
    for(int i=0;i<ans.size();i++)
    {
        if(i < ans.size()-1)
            cout<<ans[i][0]<<" "<<ans[i][1]<<" and ";
        else
            cout<<ans[i][0]<<" "<<ans[i][1];
    }
}
