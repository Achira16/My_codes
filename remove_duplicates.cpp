#include<bits/stdc++.h>
using namespace std;
vector<int> method2(vector<int>& arr)
{
    map<int,int> m;
    auto j=arr.begin();
    for(auto i=arr.begin();i!=arr.end();i++)
    {
        if(!m[*i])
        {
            m[*i] = 1;
            *j = *i;
            j++;
        }
    }
    arr.erase(j,arr.end());
    return arr;
}
vector<int> method1(vector<int>& arr)
{
    set<int> s(arr.begin(),arr.end());
    arr.assign(s.begin(),s.end());
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    arr = method2(arr);
    for(auto i=arr.begin();i!=arr.end();i++)   
        cout<<*i<<" ";
}