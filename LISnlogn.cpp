#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& active,int l,int r,int key,vector<int>& list){
    while(l < r){
        int m = (l+r)/2;
        if(key <= list[active[m]])
            r = m;
        else 
            l = m+1;
    }
    return r;
}
void lis(vector<int>& list){
    vector<int> active(list.size());
    vector<int> prevInd(list.size(),-1);
    //for getting the LIS, store the indices of the end elements in active.
    active[0] = 0;
    int length = 1;
    for(int i=1;i<list.size();i++){
        if(list[i] < list[active[0]])
            active[0] = i;
        else if(list[i] > list[active[length-1]]){
            prevInd[i] = active[length-1];
            active[length++] = i;  
        }
        else{
            int index = binarySearch(active,0,length-1,list[i],list);
            prevInd[i] = prevInd[active[index]];
            active[index] = i;
        }
    }
    cout<<length<<"\n";
    vector<int> ans;
    ans.push_back(list[active[length-1]]);
    int prev = prevInd[active[length-1]];
    while(prev != -1){
        ans.push_back(list[prev]);
        prev = prevInd[prev];
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++){
        cout<<*it<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> list(n);
    for(int i=0;i<n;i++)
        cin>>list[i];
    lis(list);
}