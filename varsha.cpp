#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr)
{
    int len = 0,min_num = INT_MAX,global_min = INT_MAX,global_len = 0;
    for(int i = 0; i < arr.size();i++)
    {
        if(arr[i] >= 100)
        {
            len++;
            min_num = min(min_num,arr[i]);
            if(len > global_len)
            {
                global_len = len;
                global_min = min_num;
            }
        }
        else
        {
            len = 0;
            min_num = INT_MAX;
        }
    }
    return global_min;
}
int main()
{
    vector<int> arr;
    int a;
    while(true)
    {
        cin>>a;
        if(a>=0)
            arr.push_back(a);
        else
            break;
    }
    cout<<func(arr);
}