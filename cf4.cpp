#include<bits/stdc++.h>
using namespace std;

int func(vector<int>& arr,int k){
    if(!k) return 0;
    sort(arr.begin(),arr.end());
    int ans = 0;
    int growth = 0;
    for(int i=11;i>=0;i--){
        growth += arr[i];
        ans++;
        if(growth >= k)
            return ans;
    }
    return -1;
}
int main(){
    int k;
    vector<int> arr(12);
    cin>>k;
    for(int i=0;i<12;i++)
        cin>>arr[i];
    cout<<func(arr,k);
}