#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define endl '\n'

int binarySearch2(vector<int>& active,int l,int r,int key){
    while(l < r){
        int m = (l+r)/2;
        if(key < active[m])
            l = m+1;
        else 
            r = m;
    }
    return r;
}
int binarySearch1(vector<int>& active,int l,int r,int key){
    while(l < r){
        int m = (l+r)/2;
        if(key <= active[m])
            r = m;
        else 
            l = m+1;
    }
    return r;
}
int lis2(vector<int>& list){
    vector<int> active(list.size());
    active[0] = list[0];
    int length = 1;
    for(int i=1;i<list.size();i++){
        if(list[i] > active[0])
            active[0] = list[i];
        else if(list[i] < active[length-1])
            active[length++] = list[i];
        else{
            int index = binarySearch2(active,0,length-1,list[i]);
            active[index] = list[i];
        }
    }
    return length;
}
int lis1(vector<int>& list){
    vector<int> active(list.size());
    active[0] = list[0];
    int length = 1;
    for(int i=1;i<list.size();i++){
        if(list[i] < active[0])
            active[0] = list[i];
        else if(list[i] > active[length-1])
            active[length++] = list[i];
        else{
            int index = binarySearch1(active,0,length-1,list[i]);
            active[index] = list[i];
        }
    }
    return length;
}
int solution(vector<int>& list){
    int k = max(lis1(list),lis2(list));
    return list.size()-k;
}
int main(){
    IOS;
    int n;
    cin>>n;
    vector<int> list(n);
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    cout<<solution(list);
}