#include<bits/stdc++.h>
using namespace std;

/* To find all permutations of a sequence of numbers, we go from ascending order to descending order. Therefore to find the next
permuation, we check for the index from the end that deviates from the descending order(we search from the end as we want to maintain
the lexicographical order), we swap this no with the smallest no greater than it...since all the nos. after this no are sorted in 
descending order we search from backwards to get the smallest one. After swapping the descending order is maintained after this index
, so we reverse it to arrive at the final ans. It is in descending order because we swapped the smallest no. greater than it with it,
so all the nos after it should either be equal or less than it.
*/
void nextPermutation(vector<int>& nums) {
        int k=-1,l;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                k=i;
                break;
            }
        }
        if(k == -1)
        {
            for(int i=0;i<nums.size()/2;i++)
            {
                swap(nums[i],nums[nums.size()-i-1]);
            }
        }
        else
        {
            for(int i=nums.size()-1;i>k;i--)
            {
                if(nums[i]>nums[k])
                {
                    l = i;
                    break;
                }
            }
            swap(nums[k],nums[l]);
            int s = nums.size()-1-k;
            for(int i=k+1,j=nums.size()-1;i<j;i++,j--)
            {
                swap(nums[i],nums[j]);
            }
        }
    }
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    nextPermutation(nums);
    for(int i:nums)
    {
        cout<<i<<" ";
    }
}