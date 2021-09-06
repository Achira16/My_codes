#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int global_max = nums[0];
    int maxprod = nums[0],minprod = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] == 0)
        {
            maxprod = minprod = 0;
        }
        else
        {
            int temp = maxprod;
            maxprod = max(nums[i],max(maxprod*nums[i],minprod*nums[i]));
            minprod = min(nums[i],min(temp*nums[i],minprod*nums[i]));
        }
        global_max = max(global_max,maxprod);
    }
    return global_max;
}
int main()
{
    
}