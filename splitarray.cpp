#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr){
    int sum = 0;
    for(auto i:arr)
        sum += i;
    int left_sum = 0,diff = INT_MAX;
    for(int i=0;i<arr.size();i++){
        left_sum += arr[i];
        int right_sum = sum-left_sum;
        diff = min(diff,abs(right_sum-left_sum));
    }
    return diff;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<func(arr);
}