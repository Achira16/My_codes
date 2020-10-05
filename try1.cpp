#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int>& p,pair<int,int>& q)
{
    return p.first<q.first;
}
int main()
{
    vector<pair<int,int>> pairs;
    pairs.push_back(make_pair(1,4));
    pairs.push_back(make_pair(1,6));
    pairs.push_back(make_pair(3,8));
    sort(pairs.begin(),pairs.end(),comparator);
    for(auto& it:pairs)
    {
        cout<<it.first<<it.second<<endl;
    }
}