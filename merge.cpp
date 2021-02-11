#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                temp[k++] = nums1[i++];
            }
            else{
                temp[k++] = nums2[j++];
            }
        }
        while(i<m){
            temp[k++] = nums1[i++];
        }
        while(j<n){
            temp[k++] = nums2[j++];
        }
        nums1.assign(temp.begin(), temp.end());
    }
int main()
{
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    int m = 3,n = 3;

    merge(a,m,b,n);
    for(auto i:a){
        cout<<i<<" ";
    }
}