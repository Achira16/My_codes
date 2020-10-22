#include<bits/stdc++.h>
using namespace std;
vector<int>::iterator b_search(vector<int>& v,int e)
{
    auto beg = v.begin(),end = v.end();
    auto mid = beg+(end-beg)/2;
    while (beg<=end)
    {
        mid = beg + (end-beg)/2;
        if(*mid == e)
            return mid;
        if(e<*mid)
            end = mid-1;
        else
            beg = mid+1;
    }
    return beg;
}
int main()
{
    vector<int> ivec = {1,2,3,4,5,7,8,10,20,29,30};
    auto mid = b_search(ivec,30);
    ivec.erase(ivec.begin(),mid);
    if(!ivec.empty())
    {for(auto& it:ivec)
    {
        cout<<it<<" ";
    }
    }
}