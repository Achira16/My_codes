#include<bits/stdc++.h>
using namespace std;

int ans;

void merge(long long *arr,int l,int mid,int r){
    int i=l,j=mid+1,k=0;
    long long temp[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            ans += mid-i+1;
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }
    k = 0;
    for(int ind=l;ind<=r;ind++){
        arr[ind] = temp[k++];
        cout<<arr[ind]<<" ";
    }
    cout<<"\n";
}
void mergesort(long long *arr,int l,int r){
    if(l < r){
        int mid = (l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    ans = 0;
    mergesort(arr,0,n-1);
    return ans;
}
int main(){
    int n;
    cin>>n;
    long long *arr = new long long(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<getInversions(arr,n);
}