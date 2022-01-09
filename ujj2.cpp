#include<bits/stdc++.h>
using namespace std;

char* FindMax(int *arr,int size){
    int cnt[10] = {0};
    int digits = 0;
    for(int i=0;i<size;i++){
        int num = arr[i];
        if(!num) cnt[0] = 1;
        else{
            while(num){
                cnt[num%10]++;
                digits++;
                num /= 10;
            }
        }
    }
    char *result = new char[digits];
    int idx = 0;
    for(int num=9;num>=0;num--){
        while(cnt[num]){
            result[idx++] = num + '0';
            cnt[num]--;
        }
    }
    return result;
}
int main(){
    // int s;
    // cin>>s;
    // int arr[s];
    // for(int i=0;i<s;i++) cin>>arr[i];
    // char *result = FindMax(arr,s);
    // cout<<result<<"\n";
    vector<int> arr(5);
    iota(arr.begin(), arr.end(), 0);
    for(int i=0;i<5;i++)    cout<<arr[i]<<" ";
}