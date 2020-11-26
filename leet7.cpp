/* 132 Pattern : Brute force #1:O(n^3): fix(i,j,k) and check a[i]<a[k] && a[k]<a[j] --->return true
    Brute force #2:O(n^2) fix (j,k) where a[j]>a[k] ,and then find i such that a[i]<a[k] ..if we find the min element
    from 0 to j-1 then our work is done...as minimum element is gonna have more chances of being less than a[k]
    To find min element in O(1) time..we need to precompute all the min elements from 0 to j-1 for all j<=n-2:
    minVal[n-2]
    minVal[0] = a[0]
    for(i=1;i<n-2;i++)
        minVal[i] = min(minVal[i-1],a[i])
    for(j=1;j<n-1;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(minVal[j-1]<a[k] and a[k]<a[j])
                return true
        }
    }
    O(n) approach: Using stack ..maintain the stack in decreasing order bcoz in this case its more likely for the element
    at the top of the stack to be less than a[j]. 
    Pop the elements that are less than the current a[j] and push a[j]
    Doubt: wat if we pop out a possible answer ...wat if there exists an a[j] < current a[j] for which it is the answer.
    Ans: Cant happen.. bcoz if it is an answer for an a[j]<current a[j] then it should also have been an answer for current a[j].
    Doubt: wat if there exists an a[j]> current a[j] for which it is an answer.
    Ans: our a[k] < current a[j]< some other a[j]...
    Case 1: MinVal for both a[j]'s is equal...if a[k]>MinVal then it should have been an answer for current a[j]
    Case 2: MinVa is unequal means minVal for our current a[j] is lower..so if its not an answer for current a[j] it cant be
    an answer for the other a[j]
*/
#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>& nums)
{
    if(nums.empty())
        return false;
    int n = nums.size();
    stack<int> s;
    vector<int> minVal(n);
    minVal[0] = nums[0];
    for(int i=1;i<n;i++)
        minVal[i] = min(minVal[i-1],nums[i]);
    for(int j=n-1;j>0;j--)
    {
        while(!s.empty() && nums[s.top()]<nums[j])
        {
            if(nums[s.top()]>minVal[j-1])
                return true;
            s.pop();
        }
        s.push(j);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<solve(nums);
}