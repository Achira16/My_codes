#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
    int minel = *min_element(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        while(!(nums[i]&1) && (nums[i]/2 >= minel))
        {
            nums[i]/=2;
        }
    }
    priority_queue<int> max_heap(nums.begin(),nums.end());
    priority_queue<int,vector<int>,greater<int>> min_heap(nums.begin(),nums.end());
    int a = max_heap.top(),b = min_heap.top();
    int diff = abs(a-b);
    if((a&1) && !(b&1))
    {
        if(abs(2*a-b/2) < abs(a-b))
        {
            diff = abs(2*a-b/2);
            max_heap.pop();
            min_heap.pop();
            max_heap.push(max(2*a,b/2));
            min_heap.push(min(2*a,b/2));
        }
    }
    else if(a&1)
    {
        if(abs(2*a-b) < abs(a-b))
        {
            diff = abs(2*a-b);
            min_heap.pop();
            
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(arr);
}