#include<bits/stdc++.h>
using namespace std;

string func(vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i < (1<<n);i++){
        int sum = 0;
        for(int bit = 0;bit < n;bit++){
            if(i & (1<<bit))
                sum += arr[bit];
            else 
                sum -= arr[bit];
        }
        if(sum%360 == 0)
            return "YES";
    }
    return "NO";
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<func(arr);
}